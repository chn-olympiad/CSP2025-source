#include<bits/stdc++.h>
using namespace std;

int n,k,a[500001],ans;
set<int> s[2097152];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		s[a[i]].insert(i);
	}int te=0;
	for(int i=1;i<=n;i++){
		if(!s[a[i-1]^k].empty()){
			auto it=s[a[i-1]^k].lower_bound(i);
			if(it!=s[a[i-1]^k].end()){
				if(i<=te){
					if(*it<=te){
						te=*it;
					}
				}else{
					te=*it;
					ans++;
				}
			}
		}
	}cout<<ans;
    return 0;
}