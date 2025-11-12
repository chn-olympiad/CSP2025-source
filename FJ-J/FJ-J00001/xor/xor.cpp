#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int ans;
int a[100005];
int b[1005][1005];
int c[100005];
int d[100005];
int main()
{
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int kk=i;kk<=j;kk++){
					b[i][j]=b[i][j]^a[kk];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[i][j]==k){
				bool flag=true;
				for(int l=i;l<=j;l++){
					if(!c[l]) c[l]=1;
					else{
						flag=false;
						break;
					}
				}
				if(flag) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
