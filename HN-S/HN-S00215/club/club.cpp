#include<bits/stdc++.h>
using namespace std;
int tt;
struct t{
	int v,x;
	bool operator <(const t &A){
		return v<A.v;
	}
};
int n,ans=0,b[4];
struct t a[100001][4];
struct mm{
	int x,y,z,i;
	bool operator <(const mm &a){
		if(a.x==x){
			if(a.y==y)
				return a.z<z;
			else
				return a.y<y;
		}else
			return a.x<x;
	}
}m[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	while(tt--){
		n=0,ans=0;
		memset(m,0,sizeof(m));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
			a[i][1].x=1,a[i][2].x=2,a[i][3].x=3;
			m[i].x=a[i][1].v,m[i].y=a[i][2].v,m[i].z=a[i][3].v,m[i].i=i;
		}
		sort(m+1,m+n+1);
		for(int i=1;i<=n;i++){
			int x=m[i].i;
			if(a[x][1].v>a[i][1].v){
				for(int j=1;j<=3;j++)
					swap(a[i][j],a[x][j]);
			}
		}
		for(int i=n;i;i--){
			for(int j=1;j<=3;j++)
				printf("%d ",a[i][j].v);
			cout<<"\n";
		}
		for(int i=n;i;i--){
			int sum=0;
			for(int j=1;j<=3;j++){
				if(b[a[i][j].x]<n/2){
					if(a[i][j].v>sum){
						sum=a[i][j].v;
						b[a[i][j].x]++;
					}
					cout<<"ans:"<<ans<<'\n';
				}
			}
			ans+=sum;
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100001][3],f[100001],d[4];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0,memset(a,0,sizeof(a)),memset(f,255,sizeof(f)),memset(d,0,sizeof(d));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		int cx=0;
		for(int i=1;i<=3;i++){
			if(a[1][i]>f[1]){
				f[1]=a[1][i];
				cx=i;
			}
		}
		d[cx]++;
		for(int i=2;i<=n;i++){
			
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}*/
