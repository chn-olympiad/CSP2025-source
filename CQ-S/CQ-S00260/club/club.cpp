#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,fl,ffl,spe[100005];
struct node{
	int x,y,z,dif,idx;
}a[100005],b[100005],c[100005];
bool f[100005];
inline bool cmp(int x,int y){
	return x>y;
} 
inline bool cmps(node x,node y){
	return x.dif>y.dif;
}
inline bool chp(node x,node y){
	return x.x>y.x;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ffl=0,fl=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].idx=i;
			if(a[i].y!=0||a[i].z!=0)ffl=1;
			if(a[i].z!=0)fl=1;
		}
		if(n==2){
			int maxx=-1e18;
			maxx=max(maxx,a[1].x+a[2].y);
			maxx=max(maxx,a[1].x+a[2].z);
			maxx=max(maxx,a[1].y+a[2].x);
			maxx=max(maxx,a[1].y+a[2].z);
			maxx=max(maxx,a[1].z+a[2].x);
			maxx=max(maxx,a[1].z+a[2].y);
			cout<<maxx<<"\n";
			continue;
			//sub 1
		}
		if(!ffl){
			int sum=0;
			for(int i=1;i<=n;i++)spe[i]=a[i].x;
			sort(spe+1,spe+n+1,cmp);
			for(int i=1;i<=n/2;i++)sum+=spe[i];
			cout<<sum<<"\n";
			continue;
			//sub 12
		}
		if(!fl){
			for(int i=1;i<=n;i++){
				a[i].dif=a[i].x-a[i].y;
			}
			sort(a+1,a+n+1,cmps);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i].x;
			}
			for(int i=n/2+1;i<=n;i++){
				sum+=a[i].y;
			}
			cout<<sum<<"\n";
			continue;
			//sub 9,13,14
		}
		if(n<=650){
			int sum=0,maxx=-1e18;
			for(int i=1;i<=n/2;i++){
				for(int j=1;j<=n/2;j++){
					sum=0;
					int ks=n-i-j;
					if(ks>n/2)continue;
					sort(a+1,a+n+1,chp);
					for(int k=1;k<=i;k++)sum+=a[k].x,f[a[k].idx]=1;
					int tnc=0;
	//				cout<<sum<<" ";
					for(int k=1;k<=n;k++){
						if(!f[i])b[++tnc].x=a[k].x,b[tnc].idx=a[k].idx;
					}
					sort(b+1,b+tnc+1,chp);
					for(int k=1;k<=j;k++)sum+=b[k].x,f[b[k].idx]=1;
	//				cout<<sum<<" "<<f[3]<<" ";
					tnc=0;
					for(int k=1;k<=n;k++){
						if(!f[i])c[++tnc].x=c[k].x,c[tnc].idx=b[k].idx;
					}
					sort(c+1,c+tnc+1,chp);
					for(int k=1;k<=ks;k++){
						if(!f[i])sum+=c[k].x;
					}
					maxx=max(maxx,sum);
	//				cout<<sum<<"\n";
					for(int i=1;i<=n;i++)f[i]=0;
				}
			}
			cout<<maxx<<"\n";
			continue;
		}
		sort(a+1,a+n+1,chp);
		int sum=0;
		for(int i=1;i<=n/2;i++)sum+=a[i].x;
		for(int i=n/2+1;i<=n;i++)sum+=a[i].y;
		cout<<sum<<"\n";
	}
	return 0;
}
/*

*/
