#include<bits/stdc++.h>
#define int long long
using namespace std;
struct S{
	int my,xb,zl;
}a[100010];
int T,t,n,vis[100010],s1,s2,s3,num;
bool cmp(S x,S y){
	return x.my>y.my;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		num=t=s1=s2=s3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int my1,my2,my3;
			cin>>my1>>my2>>my3;
			a[++t].my=my1,a[t].xb=i,a[t].zl=1;
			a[++t].my=my2,a[t].xb=i,a[t].zl=2;
			a[++t].my=my3,a[t].xb=i,a[t].zl=3;
		}
		sort(a+1,a+1+t,cmp);
		for(int i=1;i<=t;i++){
			if(!vis[a[i].xb]){
				if(a[i].zl==1&&s1+1<=n/2){
					vis[a[i].xb]=1;
					num+=a[i].my; 
					s1++;
				}else if(a[i].zl==2&&s2+1<=n/2){
					vis[a[i].xb]=1;
					num+=a[i].my; 
					s2++;
				}else if(a[i].zl==3&&s3+1<=n/2){
					vis[a[i].xb]=1;
					num+=a[i].my; 
					s3++;
				}
			}
		}
		cout<<num<<'\n';
	}
	return 0;
}

