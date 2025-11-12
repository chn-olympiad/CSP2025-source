#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500024];
bool v[500024];
long long anweihuo(long long x,long long y){
	int ax[128],ay[128],c[128],bx=0,by=0;
	for(int i=1;i<=128;i++){
		ax[i]=0;
		ay[i]=0;
		c[i]=0;
	}while(x){
		ax[++bx]=x%2;
		x/=2;
	}while(y){
		ay[++by]=y%2;
		y/=2;
	}long long maxn=max(bx,by);
	if(bx<maxn){
		while(bx<maxn){
			ax[++bx]=0;
		}
	}if(by<maxn){
		while(by<maxn){
			ay[++by]=0;
		}
	}for(long long i=1;i<=maxn;i++){
		if(ax[i]+ay[i]==1){
			c[i]=1;
		}else c[i]=0;
	}long long ans=0;
	for(long long i=max(bx,by);i>=1;i--){
		ans*=2;
		ans+=c[i];
	}return ans;
}long long anweiyu(long long x,long long y){
	int ax[128],ay[128],c[128],bx=0,by=0;
	for(int i=1;i<=128;i++){
		ax[i]=0;
		ay[i]=0;
		c[i]=0;
	}while(x){
		ax[++bx]=x%2;
		x/=2;
	}while(y){
		ay[++by]=y%2;
		y/=2;
	}long long maxn=max(bx,by);
	if(bx<maxn){
		while(bx<maxn){
			ax[++bx]=0;
		}
	}if(by<maxn){
		while(by<maxn){
			ay[++by]=0;
		}
	}for(long long i=1;i<=maxn;i++){
		if(ax[i]==ay[i]){
			c[i]=0;
		}else c[i]=0;
	}long long ans=0;
	for(long long i=max(bx,by);i>=1;i--){
		ans*=2;
		ans+=c[i];
	}return ans;
}bool qujian(long long x){
	int lx=1,rx=1,an=0;
	while(lx<=rx&&rx<=n){
		long long ans=a[lx];
		for(long long i=lx+1;i<=rx;i++){
			ans=anweihuo(ans,a[i]);
		}if(ans>k&&lx<rx){
			lx++;
		}else if(ans<k||(lx>=rx&&ans>k)){
			rx++;
		}else{
			ans=anweiyu(ans,a[lx]);
			if(ans==k){
				lx++;
			}else{
				an++;
				lx=rx+1,rx++;
			}
		}
	}return x<=an;
}int main(){
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
 	cin>>n>>k;
 	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
 		long long summ=0;
 		for(int i=1;i<=n;i++){
 			if(a[i]==0){
 				summ++;
 				v[i]=1;
			}else if(a[i]==a[i+1]&&v[i]==0&&v[i+1]==0){
				summ++;
				v[i]=1;
				v[i+1]=1;
			}
		 }cout<<summ<<endl;
		 return 0;
	}long long l=1,r=n,mid=0,sum=0;
 	while(l<=r){
 		mid=(l-r)/2+r;
 		if(qujian(mid)){
 			sum=mid;
 			l=mid+1;
		}else r=mid-1;
	}cout<<sum<<endl;
	return 0;
}

