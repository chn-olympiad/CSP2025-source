#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans = 0;
	if(n == 3){
		if(a[0] + a[1] + a[2] > a[0]*2 and a[0] + a[1] + a[2] > a[1]*2 and a[0] + a[1] + a[2] > a[2]*2){
			cout << 1;
			return 0;
		}
		else cout << 0;
		return 0;
	}
	if(n == 4){
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				for(int k=j+1;k<4;k++){
					if(a[i] + a[j] + a[k] > a[i]*2 and a[i] + a[j] + a[k] > a[j]*2 and a[i] + a[j] + a[k] > a[k]*2) ans++;
				}
			}
		}
		if(a[0] + a[1] + a[2] + a[3]> a[0]*2 and a[0] + a[1] + a[2] +a[3]> a[1]*2 and a[0] + a[1] + a[2] +a[3] > a[2]*2 and a[0] + a[1] + a[2] +a[3] > a[3]*2) ans++;
		cout << ans;
		return 0;
	}
	if(n == 5){
		for(int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				for(int k=j+1;k<5;k++){
					if(a[i] + a[j] + a[k] > a[i]*2 and a[i] + a[j] + a[k] > a[j]*2 and a[i] + a[j] + a[k] > a[k]*2) ans++;
				}
			}
		}
		for(int i=0;i<5;i++){
			for(int j=i+1;j<5;j++){
				for(int k=j+1;k<5;k++){
					for(int q=k+1;q<5;q++){
						if(a[i] + a[j] + a[k] + a[q] > a[i]*2 and a[i] + a[j] + a[k] + a[q] > a[j]*2 and a[i] + a[j] + a[k] + a[q] > a[k]*2 and a[i] + a[j] + a[k] + a[q] > a[q]*2) ans++;
					}
				}
			}
		}
		if(a[0] + a[1] + a[2] + a[3] +a[4] > 2*max(a[0],max(a[1],max(a[2],max(a[3],a[4]))))) ans++;
		cout << ans;
		return 0;
	}
	if(n == 6){
		for(int i=0;i<6;i++){
			for(int j=i+1;j<6;j++){
				for(int k=j+1;k<6;k++){
					if(a[i] + a[j] + a[k] > a[i]*2 and a[i] + a[j] + a[k] > a[j]*2 and a[i] + a[j] + a[k] > a[k]*2) ans++;
				}
			}
		}
		for(int i=0;i<6;i++){
			for(int j=i+1;j<6;j++){
				for(int k=j+1;k<6;k++){
					for(int q=k+1;q<6;q++){
						if(a[i] + a[j] + a[k] + a[q] > a[i]*2 and a[i] + a[j] + a[k] + a[q] > a[j]*2 and a[i] + a[j] + a[k] + a[q] > a[k]*2 and a[i] + a[j] + a[k] + a[q] > a[q]*2) ans++;
					}
				}
			}
		}
		for(int i=0;i<6;i++){
			for(int j=i+1;j<6;j++){
				for(int k=j+1;k<6;k++){
					for(int q=k+1;q<6;q++){
						for(int p=q+1;p<6;p++){
								if(a[i] + a[j] + a[k] + a[q] +a[p] > 2*max(a[i],max(a[j],max(a[k],max(a[q],a[p]))))) ans++;
						}
					}
				}
			}
		}
		if(a[0] + a[1] + a[2] + a[3] +a[4] + a[5]> 2*max(a[0],max(a[1],max(a[2],max(a[3],max(a[4],a[5])))))) ans++;
		cout << ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
