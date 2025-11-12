#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],s[5005],i,j,ans,l,r,k,sum,ml,mr,mx;
long long now[5005];
bool vis[5005];
void c3(){
	for(int j=1;j<=n;j++){
		for(int k=j+1;k<=n;k++){
			for(int l=k+1;l<=n;l++){
				if(a[j]+a[k]+a[l] > a[l]*2)ans++;
			}
		}
	}
}
void c4(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					if(a[i]+a[j]+a[k]+a[l] > a[l]*2)ans++;
				}
			}
		}
	}
}
void c5(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						if(a[i]+a[j]+a[k]+a[l]+a[m] > a[m]*2)ans++;
					}					
				}
			}
		}
	}
}
void c6(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=k+1;l<=n;l++){
					for(int m=l+1;m<=n;m++){
						for(int q=m+1;q<=n;q++){
							if(a[i]+a[j]+a[k]+a[l]+a[m]+a[q] > a[q]*2)ans++;
						}
					}					
				}
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	if(n == 3){
		if(a[1]+a[2] > a[3])cout << 1;
		else cout << 0;
	}
	else if(n <= 6){
		if(n == 4){
			c3();
			c4();
		}
		if(n == 5){
			c3();
			c4();
			c5();
		}
		if(n == 6){
			c3();
			c4();
			c5();
			c6();
		}
		cout << ans;
	}
	return 0;
}





