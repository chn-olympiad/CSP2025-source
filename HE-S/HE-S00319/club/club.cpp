#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n; 
int a[N][5],cha1[N],cha2[N];
int maxnum;
int ans;
int k[4],maxpt[N];
int maxx[N],minn[N],midd[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>t;
	while(t--){
		k[1]=k[2]=k[3]=0;
		cin>>n;
		maxnum=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxx[i]=max(a[i][1],max(a[i][2],a[i][3]));//第i个人的最大喜欢值 
			minn[i]=min(a[i][1],min(a[i][2],a[i][3]));
			if(a[i][1]>minn[i]&&a[i][1]<maxx[i]) midd[i]=a[i][1];
			else if(a[i][2]>minn[i]&&a[i][2]<maxx[i]) midd[i]=a[i][2];
		    else if(a[i][3]>minn[i]&&a[i][3]<maxx[i]) midd[i]=a[i][3];
		    else;
		    if(a[i][1]==maxx[i]) maxpt[i]=1,k[1]++;//第i个人最喜欢的部门编号 ,默认选这个最大值 
		    if(a[i][2]==maxx[i]) maxpt[i]=2,k[2]++;
		    if(a[i][3]==maxx[i]) maxpt[i]=3,k[3]++;
//		    if(a[i][1]==midd[i]) maxpt[i]=1; 
//		    if(a[i][2]==midd[i]) maxpt[i]=2;
//		    if(a[i][3]==midd[i]) maxpt[i]=3;
//		    if(a[i][1]==minn[i]) maxpt[i]=1;
//		    if(a[i][2]==minn[i]) maxpt[i]=2;
//		    if(a[i][3]==minn[i]) maxpt[i]=3;
		    cha1[i]=maxx[i]-midd[i];
		    cha2[i]=midd[i]-minn[i];
		    ans+=maxx[i];
		}
		sort(cha1+1,cha1+1+n);
		sort(cha2+1,cha2+1+n);
		sort(k+1,k+3+1,cmp);
		if(k[1]>maxnum){
			for(int i=1;i<=(k[1]-maxnum);i++){
				ans-=cha1[i];
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/

