#include<bits/stdc++.h>
using namespace std;

int  T;

int a[100005][3];
struct s{
	int minn,minw,maxx,maxw,num;
}b[100005];

bool cmp(s a,s b){
	if(a.minn==b.minn)return a.maxx>b.maxx;
	return a.minn<b.minn;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			b[i].minn=min(a[i][1],min(a[i][2],a[i][3]));
			if(b[i].minn==a[i][1])b[i].minw=1;
			if(b[i].minn==a[i][2])b[i].minw=2;
			if(b[i].minn==a[i][3])b[i].minw=3;
			b[i].maxx=max(a[i][1],max(a[i][2],a[i][3]));
			if(b[i].maxx==a[i][1])b[i].maxw=1;
			if(b[i].maxx==a[i][2])b[i].maxw=2;
			if(b[i].maxx==a[i][3])b[i].maxw=3;
			b[i].num=i;
		}
		int ans=0;
		int aw[4];
		aw[1]=0,aw[2]=0,aw[3]=0;
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(aw[b[i].maxw]<n/2)ans+=b[i].maxx,aw[b[i].maxw]++;
			else{
				int w1=1,maxx2=-1;
				for(w1=1;w1<=3;w1++){
					if(a[b[i].num][w1]>=maxx2 && w1!=b[i].maxw && aw[w1]<n/2)maxx2=a[b[i].num][w1];
				}
				ans+=maxx2;
				aw[w1]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
