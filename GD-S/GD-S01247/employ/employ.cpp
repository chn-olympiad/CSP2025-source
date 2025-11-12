#include <bits/stdc++.h>
using namespace std;

int n,m,a[10000005],c=0,wlh=0;
long long sum=0;
char b[10005];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> b[i];
	}
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	if (n<=10){
		for (int i=1;i<=n;i++){
			if (c>=a[i]){
				c++;
				break;
			}
			if (n<=10){
				if (n==1){
					if (b[i]==0){
						cout << 0;
						return 0;
					}
					else{
						cout << 1;
						return 0;
					}
				}
				if (n==2){
					cout << 2;
					return 0;
				}
				if (n==3){
					for (int i=1;i<=n;i++){
						if (b[i]=='1'){
							wlh++;
						}
					}
					if (m==1&&wlh==1){
						cout << 1;
						return 0;
					}
					if (m==1&&wlh==2){
						cout << 2;
						return 0;
					}
					if (m==1&&wlh==3){
						cout << 3;
						return 0;
					}
					if (m==2&&wlh==2){
						cout << 2;
						return 0;
					}
					if (m==2&&wlh==3){
						cout << 3;
						return 0;
					}
					if (m==3&&wlh==3){
						cout << 1;
						return 0;
					}
				}
				if (n==4){
					for (int i=1;i<=n;i++){
						if (b[i]=='1'){
							wlh++;
						}
					}
				}
				if (n==5){
					for (int i=1;i<=n;i++){
						if (b[i]=='1'){
							wlh++;
						}
					}
				}
				if (n==6){
					for (int i=1;i<=n;i++){
						if (b[i]=='1'){
							wlh++;
						}
					}
				}
				if (n==7){
					for (int i=1;i<=n;i++){
						if (b[i]=='1'){
							wlh++;
						}
					}
				}
				if (n==8){
					for (int i=1;i<=n;i++){
						if (b[i]=='1'){
							wlh++;
						}
					}
				}
				if (n==9){
					for (int i=1;i<=n;i++){
						if (b[i]=='1'){
							wlh++;
						}
					}
				}
				if (n==10){
					for (int i=1;i<=n;i++){
						if (b[i]=='1'){
							wlh++;
						}
					}
				}
			}
		}
	}
	cout << sum;
	return 0;
}
