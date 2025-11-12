#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			for(int k=j-1;k>=1;k--){						
				for(int l=k-1;l>=1;l--){
					if(j+k>i) ans++;
							if(j+k+l>i) ans++;
							if(k+l>i) ans++;
					for(int m=l-1;m>=1;m--){
						for(int o=m-1;o>=1;o--){
							if(j+k>i) ans++;
							if(j+k+l>i) ans++;
							if(j+k+l+m>i) ans++;
							if(j+k+l+m+o>i) ans++;
							if(k+l>i) ans++;
							if(k+l+m>i) ans++;
							if(k+l+m+o>i) ans++;
							if(l+m>i) ans++;
							if(l+m+o>i) ans++;
							if(m+o>i) ans++;
						}
					}
				}		
			}
		}
	} 
	cout<<ans;
	return 0;
}
