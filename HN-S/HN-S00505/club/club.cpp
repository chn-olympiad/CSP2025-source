#include<bits/stdc++.h>
using namespace std;
int n,limit,t;
long long ans;
int rs[4];
bool bjs[100001];
struct yy{
	int no1;
	int no2;
	int num;
}yys[100001];
bool cmp(yy a1,yy a2){
	return a1.num>a2.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		ans=0;
		cin>>n;
		memset(rs,0,sizeof(rs));
		memset(bjs,0,sizeof(bjs));
		limit=n/2;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				yys[(i-1)*3+j].no1=i;
				yys[(i-1)*3+j].no2=j;
				cin>>yys[(i-1)*3+j].num;
			}
		}
		sort(yys+1,yys+1+n*3,cmp);
		for(int i=1;i<=n*3;i++){
			if(bjs[yys[i].no1]==0 && rs[yys[i].no2]+1<=limit){
				rs[yys[i].no2]++;
				bjs[yys[i].no1]=1;
				ans+=yys[i].num;
				cout<<yys[i].no1<<' '<<yys[i].num<<'\n';
			}
		}
		cout<<ans;
	}
	return 0;
}
