#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int school[5];//第几所学校招了多少人了已经
struct node{
	int dis1;//不去最想去的学校会损失多少
	int dis2;//不去第二想去的学校会损失多少
	int a,b,c;//最，次，最不想区的学校编号
	bool vis;//该学生上没上学
	int va,vb,vc;//对应的价值
}st[100005];
bool cmp1(node a,node b){
	return a.dis1>b.dis1;
}
bool cmp2(node a,node b){
	return a.dis2>b.dis2;
}
int a[500005][5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//我们考虑，是否是先选不来该学校损失最大的呢
	int T;
	cin>>T;
	while(T--){
		memset(school,0,sizeof(school));
		memset(st,0,sizeof(st));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			int mmin=1e18,mmax=-1;
			int mxpoint=0,minpoint=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				//cout<<a[i][j]<<" ";
				if(a[i][j]>mmax){
					mmax=a[i][j];
					mxpoint=j;
				}
				if(a[i][j]<mmin){
					mmin=a[i][j];
					minpoint=j;
				}
				//cout<<mxpoint<<" "<<minpoint<<"\n";
			}
			//cout<<"\n";
			//cout<<mxpoint<<" "<<minpoint<<"\n";
			int midpoint=mxpoint^minpoint^1^2^3;
			//cout<<mmax<<"  "<<mmin<<"\n";
			int mid=a[i][midpoint];
			//cout<<mmax<<" "<<mid<<" "<<mmin<<"\n";
			int disaa=mmax-mid;
			int disbb=mid-mmin;
			//cout<<disaa<<" "<<disbb<<"\n";
			//st[i]={disa,disb,mmaxpoint,midpoint,minpoint,0,mmax,mid,mmin};
			st[i].dis1=disaa,st[i].dis2=disbb,st[i].a=mxpoint,st[i].b=midpoint,st[i].c=minpoint;
			st[i].vis=0,st[i].va=mmax,st[i].vb=mid,st[i].vc=mmin;
		}
		//第一次，按照最想区的学校排序
		int ans=0;
		sort(st+1,st+1+n,cmp1);
		/*for(int i=1;i<=n;i++){
			cout<<st[i].va<<" ";
		}*/
		for(int i=1;i<=n;i++){
			int pointa=st[i].a;
			if(school[pointa]==n/2) continue;
			school[pointa]++;
			st[i].vis=1;
			ans+=st[i].va;
			//cout<<st[i].va<<" ";
		}
		//cout<<"\n";
		sort(st+1,st+1+n,cmp2);
		for(int i=1;i<=n;i++){
			if(st[i].vis) continue;
			//cout<<i<<"\n";
			int pointb=st[i].b,pointc=st[i].c;
			if(school[pointb]==n/2){
				ans+=st[i].vc;
				st[i].vis=1;
				school[pointc]++;
				continue;
			}
			school[pointb]++;
			st[i].vis=1;
			ans+=st[i].vb;
		}
		cout<<ans<<"\n";
		
	}
	
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926


*/
