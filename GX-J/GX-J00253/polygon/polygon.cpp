#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int n,sum,ans,maxx;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n <= 3){
		for(int i = 1;i<=n;i++){
			maxx = max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>2*maxx)cout<<1<<endl;
		else cout<<0<<endl;
	}
	if(n == 4){
		for(int i = 1;i<=n;i++){
			maxx = max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>2*maxx)ans++;
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					sum  = a[i]+a[j]+a[k];
					maxx = max(a[i],a[j]);
					maxx = max(maxx,a[k]);
					if(sum>2*maxx)ans++;
				}
		cout<<ans<<endl;
				
	}
	if(n == 5){
		for(int i = 1;i<=n;i++){
			maxx = max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>2*maxx)ans++;
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					sum  = a[i]+a[j]+a[k];
					maxx = max(a[i],a[j]);
					maxx = max(maxx,a[k]);
					if(sum>2*maxx)ans++;
				}
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					for(int q = k+1;q<=n;q++){
						sum  = a[i]+a[j]+a[k]+a[q];
						maxx = max(a[i],a[j]);
						maxx = max(maxx,a[k]);
						maxx = max(maxx,a[q]);
						if(sum>2*maxx)ans++;
					}
				}
		cout<<ans<<endl;
				
	}
	if(n == 6){
		for(int i = 1;i<=n;i++){
			maxx = max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>2*maxx)ans++;
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					sum  = a[i]+a[j]+a[k];
					maxx = max(a[i],a[j]);
					maxx = max(maxx,a[k]);
					if(sum>2*maxx)ans++;
				}
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					for(int q = k+1;q<=n;q++){
						sum  = a[i]+a[j]+a[k]+a[q];
						maxx = max(a[i],a[j]);
						maxx = max(maxx,a[k]);
						maxx = max(maxx,a[q]);
						if(sum>2*maxx)ans++;
					}
				}
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					for(int q = k+1;q<=n;q++){
						for(int w = q+1;w<=n;w++){
							sum  = a[i]+a[j]+a[k]+a[q]+a[w];
							maxx = max(a[i],a[j]);
							maxx = max(maxx,a[k]);
							maxx = max(maxx,a[q]);
							maxx = max(maxx,a[w]);
							if(sum>2*maxx)ans++;
						}
						
					}
				}
		cout<<ans<<endl;
				
	}	
	if(n == 6){
		for(int i = 1;i<=n;i++){
			maxx = max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>2*maxx)ans++;
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					sum  = a[i]+a[j]+a[k];
					maxx = max(a[i],a[j]);
					maxx = max(maxx,a[k]);
					if(sum>2*maxx)ans++;
				}
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					for(int q = k+1;q<=n;q++){
						sum  = a[i]+a[j]+a[k]+a[q];
						maxx = max(a[i],a[j]);
						maxx = max(maxx,a[k]);
						maxx = max(maxx,a[q]);
						if(sum>2*maxx)ans++;
					}
				}
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					for(int q = k+1;q<=n;q++){
						for(int w = q+1;w<=n;w++){
							sum  = a[i]+a[j]+a[k]+a[q]+a[w];
							maxx = max(a[i],a[j]);
							maxx = max(maxx,a[k]);
							maxx = max(maxx,a[q]);
							maxx = max(maxx,a[w]);
							if(sum>2*maxx)ans++;
						}
						
					}
				}
		for(int i = 1;i<=n;i++)
			for(int j = i+1;j<=n;j++)
				for(int k = j+1;k<=n;k++){
					for(int q = k+1;q<=n;q++){
						for(int w = q+1;w<=n;w++){
							for(int e = w+1;e<=n;e++){
								sum  = a[i]+a[j]+a[k]+a[q]+a[w]+a[e];
								maxx = max(a[i],a[j]);
								maxx = max(maxx,a[k]);
								maxx = max(maxx,a[q]);
								maxx = max(maxx,a[w]);
								maxx = max(maxx,a[e]);
								if(sum>2*maxx)ans++;
							}
							
						}
						
					}
				}
		cout<<ans<<endl;
				
	}	
	
	



	return 0;
}
