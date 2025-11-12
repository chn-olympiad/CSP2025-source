#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt,x;
stack <int>s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(long long i=1;i<=n;i++){
			if(a[i]==0)  cnt++;
			if(!s.empty()){
				x=s.top();
				if(x==a[i]){
					cnt++;
					s.pop();
				}
			}
			else s.push(a[i]);
		}
	}
	if(k==1){
		for(long long i=1;i<=n;i++){
			if(a[i]==1){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}