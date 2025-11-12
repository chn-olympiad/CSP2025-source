#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],b[3][100005],c[3],cnt[3],s,x,y,z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;s=0;
		cnt[0]=cnt[1]=cnt[2]=0;
		c[0]=c[1]=c[2]=0;
		for(int i=1;i<=n;i++){
			x=-1,y=-1,z=-1;
			for(int j=0;j<=2;j++){
				cin>>a[i][j];
				if(a[i][j]>x){
					z=x;
					x=a[i][j];
					y=j;
				}
				else z=max(z,a[i][j]);
			}
			s+=x;
			cnt[y]++;
			b[y][++c[y]]=x-z;
			
		}
		for(int i=0;i<=2;i++)
			if(cnt[i]*2>n){
				int k=cnt[i]-n/2;
				sort(b[i]+1,b[i]+c[i]+1);
				for(int j=1;j<=k;j++)s-=b[i][j];
			}
		cout<<s<<'\n';
	}
	return 0;
}
