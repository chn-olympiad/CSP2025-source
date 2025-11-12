#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int N=1e5 +5;
struct node{
	int id,w;
}a[N][5],x[5][N],c[5][N];
int n,m[5],ans,t,cnt[5];
bool cmp(node x,node y){
	return x.w<y.w;
}
bool cmp1(node x,node y){
	return x.w>y.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		memset(x,0,sizeof(x));
		memset(c,0,sizeof(c));
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1].w>>a[i][2].w>>a[i][3].w;
			a[i][1].id=1;a[i][2].id=2;a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp1);
			x[a[i][1].id][++cnt[a[i][1].id]]=a[i][1];
			c[a[i][1].id][cnt[a[i][1].id]].w=a[i][1].w-a[i][2].w;
			c[a[i][1].id][cnt[a[i][1].id]].id=a[i][2].id;
		}
		if(cnt[1]>cnt[2]&&cnt[1]>cnt[3]){
			m[1]=1;
			if(cnt[2]>cnt[3])m[2]=2,m[3]=3;
			else m[2]=3,m[3]=2;
		}
		if(cnt[2]>cnt[1]&&cnt[2]>cnt[3]){
			m[1]=2;
			if(cnt[1]>cnt[3])m[2]=1,m[3]=3;
			else m[2]=3,m[3]=1;
		}
		if(cnt[3]>cnt[2]&&cnt[3]>cnt[1]){
			m[1]=3;
			if(cnt[1]>cnt[2])m[2]=1,m[3]=2;
			else m[2]=2,m[3]=1;
		}
		sort(c[m[1]]+1,c[m[1]]+cnt[m[1]]+1,cmp);
		for(int k=1;k<=cnt[m[1]]-n/2;k++){
		//	cout<<c[m[1]][k].w<<" ";
			int j=m[1];
			
			ans-=c[j][k].w;
		//	x[c[j][k].id][cnt[c[j][k].id]].w=a[k][2].w;
			//x[j][k]=node{0,0};
		}
	//	cout<<ans<<"\n";
		for(int i=1;i<=3;i++){
			for(int j=1;j<=cnt[i];j++){
				ans+=x[i][j].w;
			//	cout<<x[i][j].w<<" ";
			}
		//	cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	//cout<<t<<"\n";
	return 0;
} 
