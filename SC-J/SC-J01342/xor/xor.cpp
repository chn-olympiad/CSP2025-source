#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,kk,ans,v[3000010],a[3000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>kk;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<n-i+1;j++){
			int q=a[j];
			bool flag=1;
			for(int k=j+1;k<j+i;k++){
				if(v[k]==1) flag=0;
				q=q^a[k];
			}
			if(flag==0) continue;
			if(q==kk){
				ans++;
				for(int k=j;k<j+i;k++) v[k]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}