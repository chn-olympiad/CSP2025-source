#include<bits/stdc++.h>
using namespace std;
int a[(int)2e5][5];
int mx[(int)2e5],se[(int)2e5],id[(int)2e5];
int T,n;
int cnt[5];
bool cmp(int x,int y){return a[x][mx[x]]-a[x][se[x]]>a[y][mx[y]]-a[y][se[y]];}
void clean(){
	for(int i=1;i<=3;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)mx[i]=se[i]=0;
}
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int Mx=max({a[i][1],a[i][2],a[i][3]});
			if(Mx==a[i][1])mx[i]=1;
			else if(Mx==a[i][2])mx[i]=2;
			else mx[i]=3;
			if(mx[i]==1)se[i]=a[i][2]>=a[i][3]?2:3;
			else if(mx[i]==2)se[i]=a[i][1]>=a[i][3]?1:3;
			else se[i]=a[i][1]>=a[i][2]?1:2;
			id[i]=i;
		}sort(id+1,id+n+1,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[mx[id[i]]]<n/2)cnt[mx[id[i]]]++,ans+=a[id[i]][mx[id[i]]];
			else cnt[se[id[i]]]++,ans+=a[id[i]][se[id[i]]];
		}cout<<ans<<'\n';clean();
	}
} 
