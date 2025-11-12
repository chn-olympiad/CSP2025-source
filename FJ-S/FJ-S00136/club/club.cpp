#include<bits/stdc++.h>
using namespace std;
struct stu{
	int n,a,b,c;
}s[100005];
int t,n,a[100005][4],c[4];
long long ans;
vector<int> cnt[4];
bool cmp(int x,int y){
	return a[x][s[x].a]-a[x][s[x].b]>a[y][s[y].a]-a[y][s[y].b];
}
bool cmp2(int x,int y){
	return a[x][s[x].b]-a[x][s[x].c]>a[y][s[y].b]-a[y][s[y].c];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0,cnt[1]=cnt[2]=cnt[3]=vector<int>();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int maxx=0,maxj,minn=INT_MAX,minj;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>=maxx){
					maxx=a[i][j];
					maxj=j;
				}
				if(a[i][j]<=minn){
					minn=a[i][j];
					minj=j;
				}
			}
			ans+=maxx;
			s[i].n=i,s[i].a=maxj,s[i].b=6-maxj-minj,s[i].c=minj;
			cnt[maxj].push_back(i);
		}
		for(int i=1;i<=3;i++){
			if(cnt[i].size()>n/2) sort(cnt[i].begin(),cnt[i].end(),cmp);
			while(cnt[i].size()>n/2){
				int no=cnt[i].back();
				cnt[i].pop_back();
				cnt[s[no].b].push_back(no);
				ans=ans-a[no][i]+a[no][s[no].b];
			}
		}
		for(int i=1;i<=3;i++){
			if(cnt[i].size()>n/2) sort(cnt[i].begin(),cnt[i].end(),cmp2);
			while(cnt[i].size()>n/2){
				int no=cnt[i].back();
				cnt[i].pop_back();
				cnt[s[no].c].push_back(no);
				ans=ans-a[no][i]+a[no][s[no].c];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

