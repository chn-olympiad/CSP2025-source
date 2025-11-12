#include<bits/stdc++.h>
using namespace std;
long long n,k,eer[64],kk[64],g[64],x,weix,ans;
struct shu{
	int shi;
	int er;
	int wei;
}a[500010];
struct shuu{
	int shi;
	int er;
	int wei;
}b[500010];
void zhuan(long long x){
	int x1=x;
	int g[64];	x1=x;
	for(int i=1;x1>0;i++){
		g[i]=x1%2;
		x1/=2;
		weix++;
	}
	x=0;
	for(int i=weix;i>=1;i--){
		x+=g[i];
		x*=10;
	}
	x/=10;
	k=x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	zhuan(k);
	for(int i=1;i<=n;i++){
		cin>>a[i].shi;
		for(int j=1;j<=64;j++)
			eer[i]=0;
		while(a[i].shi>0){
			a[i].wei++;
			eer[a[i].wei]=a[i].shi%2;
			a[i].shi/=2;
		}
		for(int j=a[i].wei;j>=1;j--){
			a[i].er+=eer[j];
			a[i].er*=10;
		}
		a[i].er/=10;
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			for(int p=1;p<=n;p++){
				b[p].er=a[p].er;
				b[p].shi=a[p].shi;
				b[p].wei=a[p].wei;
			}
			for(int p=i+1;p<=j;p++){
//				cout<<b[p-1].er<<" "<<b[p].er<<"-->";
//				for(int q=1;q<=max(a[p-1].wei,a[p].wei);q++){
					int e1[64];
					int e2[64],t=0,t1=0;
					while(b[p-1].er>0){
						t++;
						e1[t]=b[p-1].er%10;
						b[p-1].er/=10;
					}
					while(b[p].er>0){
						t1++;
						e2[t1]=b[p].er%10;
						b[p].er/=10;
					}
					int tt=max(t,t1);
					for(int u=1;u<=tt;u++){
						if(e1[u]!=e2[u]){
							e1[u]=1;
						}else{
							e1[u]=0;
						}
					}
					b[p].er=0;
					for(int u=tt;u>=1;u--){
						b[p].er+=e1[u];
						b[p].er*=10;
					}
					b[p].er/=10;
//				} 
			}
			if(b[j].er==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
