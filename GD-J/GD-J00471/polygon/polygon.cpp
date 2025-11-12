#include <iostream>
using namespace std;
#define ll long long
int a[5010];
ll m=998244353;
ll jc(int k){
	if(k<=1)
		return 1;
	ll ans=1;
	for(int i=2;i<=k;i++){
		ans*=i;
		ans%=m;
	}
	return ans;
}
ll cp(int n,int m){
	return (jc(n)/jc(m))/jc(n-m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool p=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)
			p=false;
	}
	ll res=0;
	if(p){
		for(int i=3;i<=n;i++){
			res+=cp(n,i);
			res%=m;
		}
	}
	else{
		int sum=0,ma=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			if(a[i]>ma)
				ma=a[i];
		}
		if(sum>ma*2)
			res++;
		if(n>=4){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					int t=max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>t*2)
						res++;
				}
			}
		}
		if(n>=5){
			for(int i=1;i<=n-3;i++){
			for(int j=i+1;j<=n-2;j++){
				for(int k=j+1;k<=n-1;k++){
					for(int q=k+1;q<=n;q++){
					int t=max(max(a[i],a[j]),max(a[k],a[q]));
					if(a[i]+a[j]+a[k]+a[q]>t*2)
						res++;
					}
				}
			}
		}
		}
		if(n>=6){
			for(int i=1;i<=n-4;i++){
			for(int j=i+1;j<=n-3;j++){
				for(int k=j+1;k<=n-2;k++){
					for(int q=k+1;q<=n-1;q++){
					for(int s=q+1;s<=n;s++){
					int t=max(max(max(a[i],a[j]),max(a[k],a[q])),a[s]);
					if(a[i]+a[j]+a[k]+a[q]+a[s]>t*2)
						res++;
					}
				}
				}
			}
		}
		if(n>=7){
			for(int i=1;i<=n-5;i++){
			for(int j=i+1;j<=n-4;j++){
				for(int k=j+1;k<=n-3;k++){
					for(int q=k+1;q<=n-2;q++){
					for(int s=q+1;s<=n-1;s++){
					for(int u=s+1;u<=n;u++){
					int t=max(max(max(a[i],a[j]),max(a[k],a[q])),max(a[s],a[u]));
					if(a[i]+a[j]+a[k]+a[q]+a[s]+a[u]>t*2)
						res++;
					}}
				}
				}
			}
		}
		}
		if(n>=8){
			for(int i=1;i<=n-6;i++){
			for(int j=i+1;j<=n-5;j++){
				for(int k=j+1;k<=n-4;k++){
					for(int q=k+1;q<=n-3;q++){
					for(int s=q+1;s<=n-2;s++){
					for(int u=s+1;u<=n-1;u++){
					for(int v=u+1;v<=n;v++){
					int t=max(max(max(a[i],a[j]),max(a[k],a[q])),max(max(a[s],a[v]),a[u]));
					if(a[i]+a[j]+a[k]+a[q]+a[s]+a[u]+a[v]>t*2)
						res++;
					}}
				}
				}
				}
			}
		}
		}
		if(n>=9){
			for(int i=1;i<=n-7;i++){
			for(int j=i+1;j<=n-6;j++){
				for(int k=j+1;k<=n-5;k++){
					for(int q=k+1;q<=n-4;q++){
					for(int s=q+1;s<=n-3;s++){
					for(int u=s+1;u<=n-2;u++){
					for(int v=u+1;v<=n-1;v++){
					for(int w=v+1;w<=n;w++){
					int t=max(max(max(a[i],a[j]),max(a[k],a[q])),max(max(a[s],a[v]),max(a[u],a[w])));
					if(a[i]+a[j]+a[k]+a[q]+a[s]+a[u]+a[v]+a[w]>t*2)
						res++;
					}}}
				}
				}
				}
			}
		}
		if(n>=10){
			for(int i=1;i<=n-8;i++){
			for(int j=i+1;j<=n-7;j++){
				for(int k=j+1;k<=n-6;k++){
					for(int q=k+1;q<=n-5;q++){
					for(int s=q+1;s<=n-4;s++){
					for(int u=s+1;u<=n-3;u++){
					for(int v=u+1;v<=n-2;v++){
					for(int w=v+1;w<=n-1;w++){
					for(int x=w+1;x<=n;x++){
					int t=max(max(max(a[i],a[j]),max(a[k],a[q])),max(max(a[s],a[v]),max(a[u],max(a[w],a[x]))));
					if(a[i]+a[j]+a[k]+a[q]+a[s]+a[u]+a[v]+a[w]+a[x]>t*2)
						res++;
					}}}}
				}
				}
				}
			}
		}
		}
		}
		}
	}
	}
	cout<<res%m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
