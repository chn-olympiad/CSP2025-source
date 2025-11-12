#include<bits/c++io.h>
using namespace std;
int main(){
	int n,c;
	cin>>n;
	if(n<3){
		cout <<'0';
	}
	elae{
		int a[n+5];
		for(int i=0;i<=n;i++){
			cin>>a[i];
		}
		if(n==3){
			for(int i=0;i<=n;i++){
				for(int k=i+1;k<=n;k++){
					for(int j=k+1;j<=n;j++){
						if(a[i]>=a[k] && a[i]>=a[j]){
							if(a[k]+a[j]>a[i]){
								c++;
							}
						}
						if(a[k]>=a[i] && a[k]>=a[j]){
							if(a[i]+a[j]>a[k]){
								c++;
							}
						}
						if(a[j]>=a[k] && a[j]>=a[j]){
							if(a[k]+a[i]>a[j]){
								c++;
							}
						}
					}
				}
			}
		}
		if(n==4){
			for(int i=0;i<=n;i++){
				for(int k=i+1;k<=n;k++){
					for(int j=k+1;j<=n;j++){
						for(int l=j+1;l<=n;l++)
							if(a[i]>=a[k] && a[i]>=a[j] && a[i]>a[l]){
								if(a[k]+a[j]+a[l]>a[i]*2){
									c++;
								}
							}
							if(a[k]>=a[i] && a[k]>=a[j] && a[k]>a[l]){
								if(a[i]+a[j]+a[l]>a[k]*2){
									c++;
								}
							}
							if(a[j]>=a[k] && a[j]>=a[i] && a[j]>a[l]){
								if(a[k]+a[i]+a[l]>a[j]*2){
									c++;
								}
							}
							if(a[l]>=a[k] && a[l]>=a[j] && a[l]>a[i]){
								if(a[k]+a[i]+a[j]>a[l]*2){
									c++;
								}
							}
						}
					}
				}
			}
		}
		cout<<n;
    }
	return 0;
}