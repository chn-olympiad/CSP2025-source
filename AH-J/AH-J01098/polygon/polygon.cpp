#include <bits/stdc++.h>
using namespace std;
int a[50001];
int b[50001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+n+1);
	int ans=0;
	if(b[1]==n){
		for(int i=3;i<=n;i++){
			for(int j=n;j<=n;j++){
				int ans1=1,ans2=1;
				for(int k=1;k<=i;k++){
					ans1*=(j-k+1);
					ans2*=k;
				}
				
				ans+=ans1/ans2;
			}
		}
		cout<<ans;
		return 0;
	}else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	else if(n<=10){
		if(n==4){
			
				for(int i1=1;i1<=n;i1++){
					for(int i2=i1+1;i2<=n;i2++){
						for(int i3=i2+1;i3<=n;i3++){
								if(a[i1]+a[i2]>a[i3]*2){
									ans++;
								}
						}
					}
				}
			
			
				for(int i1=1;i1<=n;i1++){
					for(int i2=i1+1;i2<=n;i2++){
						for(int i3=i2+1;i3<=n;i3++){
							for(int i4=i3+1;i4<=n;i4++){
								if(a[i1]+a[i2]+a[i3]>a[i4]*2){
									ans++;
								}
							}
						}
					}
				}
			
		}
		cout<<ans;
		
		return 0;
	}
	else{
		cout<<0;
	}
	return 0;
}
