#include <bits/stdc++.h>
using namespace std;
long long n,a[9999999999],ans=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	if(n==3&&a[0]+a[1]+a[2]>max(a[1],max(a[0],a[2]))){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<n;++i){
		long long now=a[i],x=1,maxn=a[i];
		for(int j=i+1;j<n;++j){
			now+=a[j],++x,maxn=max(maxn,a[j]);
			for(int k=j+1;k<n;++k){
				now+=a[k],++x,maxn=max(maxn,a[k]);
				for(int p=k+1;p<n;++p){
					if(x>=3&&now>2*maxn){
						if(now-maxn*2>=a[p])
							if(a[p]<maxn)
								ans*=2;
							else
								ans+1;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
