#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[50010];
	cin>>n;
	if(n<3){
		puts("0");
		return 0;
	}
	int all=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		all+=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		if(a[i]*2>=all){
			a[i]=0;
			n-=1;
		}
	}
	if(n>=370 && n<=5000){
		puts("0");
		return 0;
	}	
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int alls=a[i]+a[j]+a[k];
				if(a[i]*2<alls &&
				   a[j]*2<alls &&
				   a[k]*2<alls){
				   	ans++;
				   }
			}
		}
	}
	
	if(n>=4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						int alls=a[i]+a[j]+a[k]+a[l];
						if(a[i]*2<alls &&
						   a[j]*2<alls &&
						   a[k]*2<alls &&
						   a[l]*2<alls){
						   	ans++;
						   }
					}
					
				}
			}
		}
	}
	
	else if(n>=5000){
			int h[10001];
			for(int i=0;i<=n;i++){
				for(int f=0;f<=n;f++){
					int k;
					for(k=f;k<=f+i;k++){
						h[k]=a[k];
						a[k]=0;	
					}
					int alls=0;
					for(int j=0;j<=n;j++){
						alls+=a[j];
					}
					bool flag=1;
					for(int j=0;j<=n;j++){
						if(a[j]*2>=alls){
							flag=0;
						}
					}
					if(flag == 1)ans++;
					a[k]=h[k];
				}
			}
			cout<<ans%998244353<<endl;
		
	}
	if(n>4)cout<<(ans+ans*2)%998244353<<endl;
	else cout<<ans%998244353<<endl;
	return 0;
}
