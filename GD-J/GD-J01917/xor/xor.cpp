#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans,jl=1,num;
bool p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(jl<=n){
		int l=jl,r=n;
		p=0;
		while(l<r){
			num=0;
			for(int i=l;i<=r;i++){
				num=num^a[i];
				if(num==k){
					r=i;
					p=1;
				}
			}
			l++;
		}
		if(p){
			ans++;
			jl=r+1;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
