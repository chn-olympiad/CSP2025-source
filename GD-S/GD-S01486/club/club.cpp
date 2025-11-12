#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
int pr[210][5];
int f[210][110][110];
struct ps{
	int a,b,c;
	int ma;
}pt[100010];
bool cmp1(ps x,ps y){
	if(x.a>y.a)return 1;
	else return 0;
}
bool cmp2(ps x,ps y){
	if(x.ma>y.ma)return 1;
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int m=n/2;
		if(n<100000){
			for(int i=1;i<=n;i++){
				cin>>pr[i][1]>>pr[i][2]>>pr[i][3];
			}
			for(int i=1;i<=n;i++){
				for(int j=0;j<=m;j++){
					for(int k=0;k<=m;k++){
						int l=i-j-k-1;
						if(l>m||l<0)continue;
						if(j+1<=m)f[i][j+1][k]=max(f[i][j+1][k],f[i-1][j][k]+pr[i][1]);
						if(k+1<=m)f[i][j][k+1]=max(f[i][j][k+1],f[i-1][j][k]+pr[i][2]);
						if(l+1<=m)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+pr[i][3]);
					}
				}
			}
			int ans=0;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					ans=max(ans,f[n][i][j]);
				}
			}
			cout<<ans<<endl;
			memset(f,0,sizeof(f));
		}else{
			int mark1=0,mark2=0;
			for(int i=1;i<=n;i++){
				cin>>pt[i].a>>pt[i].b>>pt[i].c;
				pt[i].ma=max(pt[i].a,pt[i].b);
				if(pt[i].b!=0||pt[i].c!=0)mark1=1;
				if(pt[i].c!=0)mark2=1;
			}
			if(mark1==0){
				sort(pt+1,pt+1+n,cmp1);
				int ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=pt[i].a;
				}
				cout<<ans<<endl;
			}else if(mark2==0){
				sort(pt+1,pt+1+n,cmp2);
				int rest1=n/2,rest2=n/2;
				int ans=0;
				for(int i=1;i<=n;i++){
					if(rest1==0){
						ans+=pt[i].b; 
					}else if(rest2==0){
						ans+=pt[i].a;
					}else{
						if(pt[i].ma==pt[i].a){
							rest1--;
							ans+=pt[i].a;
						}else{
							rest2--;
							ans+=pt[i].b;
						}
					}
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
