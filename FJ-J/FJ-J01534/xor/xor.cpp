#include<bits/stdc++.h>
using namespace std;
int n,k,p,l,mx;
int r[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			p=0;
			for(int o=i;o<=j;o++){
				p=p^r[o];
			}
			if(p==k&&i>mx){
				mx=max(j,mx);
				l++;
			}
		}
	}
	cout<<l<<endl;
	return 0;
}
