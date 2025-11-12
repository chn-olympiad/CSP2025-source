#include<bits/stdc++.h>
using namespace std;
int a[5005],n,ans;


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3)
	if(a[1]+a[2]>a[3]) cout<<1;
	else cout<<0;
	if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k]&&i!=k) ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int m=k+1;m<=n;m++){
						if(a[i]+a[j]+a[k]>a[m]&&j!=k&&k!=m&&j!=m) ans++;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
