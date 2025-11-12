#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t;
int n;
int a1[N],a2[N],a3[N];
bool cmp(int a,int b){
	return a>b;
}
struct node{
	int b1,b2,b3;
}b[N];
struct node1{
	int c1,c2,c3;
}c[N];
bool cmp1(node x,node y){
	if(x.b1==y.b1) return x.b2>y.b2;
	return x.b1>y.b1;
}
bool cmp2(node1 x,node1 y){
	if(x.c2==y.c2) return x.c1>y.c1;
	return x.c2>y.c2;
}
bool vis1[N],vis2[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool f=true,f1=true;
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			b[i].b1=a1[i],b[i].b2=a2[i],b[i].b3=a3[i];
			c[i].c1=a1[i],c[i].c2=a2[i],c[i].c3=a3[i];
			if(a2[i]!=0) f=false;
			if(a3[i]!=0) f1=false;
		}
		if(n==2){
			int ans1=max(a1[1]+a2[2],a1[2]+a2[1]),ans2=max(a1[1]+a3[2],a1[2]+a3[1]);
			int ans3=max(a2[1]+a3[2],a2[2]+a3[1]),mx=max(ans1,ans2);
			cout<<max(ans3,mx)<<"\n";
		}
		if(n==4){
			int mx=-1;
			for(int i=2;i<=4;i++){
				int ans=a1[1]+a1[i];
				for(int j=1;j<=n;j++){
					if(j==1||j==i) continue;
					for(int k=1;k<=n;k++){
						if(k==1||k==i||k==j) continue;
						ans+=a2[j]+a3[k];
						mx=max(ans,mx);
					}
				}
			}
			for(int i=2;i<=4;i++){
				int ans=a2[1]+a2[i];
				for(int j=1;j<=n;j++){
					if(j==1||j==i) continue;
					for(int k=1;k<=n;k++){
						if(k==1||k==i||k==j) continue;
						ans+=a1[j]+a3[k];
						mx=max(ans,mx);
					}
				}
			}
			for(int i=2;i<=4;i++){
				int ans=a3[1]+a3[i];
				for(int j=1;j<=n;j++){
					if(j==1||j==i) continue;
					for(int k=1;k<=n;k++){
						if(k==1||k==i||k==j) continue;
						ans+=a2[j]+a1[k];
						mx=max(ans,mx);
					}
				}
			}
			cout<<mx<<"\n";
			continue;
		}
		if(f1){
			if(f){
				int ans=0;
				sort(a1+1,a1+n+1,cmp);
				for(int i=1;i<=n/2;i++) ans+=a1[i];
				cout<<ans<<"\n";
			}else{
				if(n%2==0){
					sort(b+1,b+n+1,cmp1);
					sort(c+1,c+n+1,cmp2);
					int ans1=0,ans2=0;
					for(int i=1;i<=n/2;i++) ans1+=b[i].b1;
					for(int i=n/2+1;i<=n;i++) ans1+=b[i].b2;
					for(int i=1;i<=n/2;i++) ans2+=c[i].c2;
					for(int i=n/2+1;i<=n;i++) ans2+=c[i].c1;
					cout<<max(ans1,ans2)<<"\n";
				}else{
					sort(b+1,b+n+1,cmp1);
					sort(c+1,c+n+1,cmp2);
					int ans1=0,ans2=0;
					for(int i=1;i<=n/2+1;i++) ans1+=b[i].b1;
					for(int i=n/2+2;i<=n;i++) ans1+=b[i].b2;
					for(int i=1;i<=n/2+1;i++) ans2+=c[i].c2;
					for(int i=n/2+2;i<=n;i++) ans2+=c[i].c1;
					cout<<max(ans1,ans2)<<"\n";
				}
			}
		}
	}
	return 0;
}
