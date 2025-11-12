#include<bits/stdc++.h>
using namespace std;
int t,n;
int f[100010][5];
int dis[5];
struct node{
	int maxx;
	int count1;
}a[100010];
bool cmp(node x,node y){
	return x.maxx>y.maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t){
		int ans=0;
		cin>>n;
		memset(dis,0,sizeof(dis));
		for (int i=1;i<=n;i++){
			int max1=0,count2=0;
			for (int j=1;j<=3;j++){
				cin>>f[i][j];
				if (f[i][j]>max1){
					max1=f[i][j];
					count2=j;
				}
			}
			a[i].maxx=max1;
			a[i].count1=count2;
		}
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n;i++){
			int w=n/2;
			if (dis[a[i].count1]<w){
				dis[a[i].count1]++;
				ans+=a[i].maxx;
			}
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
