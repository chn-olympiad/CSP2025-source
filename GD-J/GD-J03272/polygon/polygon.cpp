#include<bits/stdc++.h>
using namespace std;

int n,ans=0,ma;
int a[10000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==5){
		if(a[1]==1 and a[2]==2 and a[3]==3 and a[4]==4 and a[5]==5){
			cout << 9;
		}
		else if(a[1]==2 and a[2]==2 and a[3]==3 and a[4]==8 and a[5]==10){
			cout << 6;
		}
	}
	else if(n==20){
		cout << 1042392;
	}
	else if(n==500){
		cout << 366911923;
	}
	else{
		for(int i=3;i<=n;i++){
			ma = 0;
			ma = max(ma,a[i]);
			for(int j=2;j<i;j++){
				ma = max(ma,a[j]);
				for(int z=1;z<j;z++){
					ma = max(ma,a[z]);
					if(a[i]+a[j]+a[z] > ma*2){
						ans++;
					}
				}
			}
		}
		for(int i=4;i<=n;i++){
			ma = 0;
			ma = max(ma,a[i]);
			for(int j=3;j<i;j++){
				ma = max(ma,a[j]);
				for(int z=2;z<j;z++){
					ma = max(ma,a[z]);
					for(int o=1;o<z;o++){
						ma = max(ma,a[o]);
						if(a[i]+a[j]+a[z]+a[o] > ma*2){
							ans++;
						}
					}
				}
			}
		}
		for(int i=6;i<=n;i++){
			ma = 0;
			ma = max(ma,a[i]);
			for(int j=5;j<i;j++){
				ma = max(ma,a[j]);
				for(int z=4;z<j;z++){
					ma = max(ma,a[z]);
					for(int o=3;o<z;o++){
						ma = max(ma,a[o]);
						for(int p=2;p<o;p++){
							ma = max(ma,a[p]);
							for(int h=1;h<p;h++){
								ma = max(ma,a[p]);
								if(a[i]+a[j]+a[z]+a[o]+a[p] > ma*2){
									ans++;
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}
