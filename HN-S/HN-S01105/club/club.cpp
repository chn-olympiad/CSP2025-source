#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct sam{
	int x,y,z;
}a[N][3];
int b[N][3];
int t,n,k,st[4];
sam c[N];
bool cmp(sam l,sam r){
	if(l.x>r.x){
		return 1;
	}else if(l.x==r.x&&l.z>r.z){
		return 1;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int sum=0;
		cin>>n;
		k=n>>1;
		for(int i=1;i<=n;i++){
			c[i].x=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>b[i][j];
				c[i].y=i;
				c[i].x+=b[i][j];
				c[i].z=max(c[i].z,b[i][j]);
			}
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j].x=b[c[i].y][j];
				a[i][j].y=j;
			}
		}
		for(int i=1;i<=3;i++){
			int ans=0;
			memset(st,0,sizeof(st));
			ans+=a[1][i].x;
			st[a[1][i].y]++;
			for(int j=2;j<=n;j++){
				int mx=0,h;
				for(int l=1;l<=3;l++){
					if(mx<a[j][l].x&&st[l]+1<=k){
						mx=a[j][l].x;
						h=l;
					}
				}
				ans+=mx;
				st[h]++;
			}
			sum=max(sum,ans);
		}
		cout<<sum<<"\n";
	}
	return 0;
}
