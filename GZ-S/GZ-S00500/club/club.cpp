//GZ-S00500 北京师范大学贵阳附属学校 黄人麟 
#include<bits/stdc++.h>
using namespace std;
#define num first
#define id second
const int N=1e5+10;
int T,n,a[N][4];
priority_queue<int> ans;
pair<int,int> fi[N],se[N],th[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]){
				fi[i].num=a[i][1],fi[i].id=1;
				se[i].num=a[i][2],se[i].id=2;
				th[i].num=a[i][3],th[i].id=3;
				continue;
			}
			int t=a[i][1]+a[i][2]+a[i][3];
			fi[i].num=max({a[i][1],a[i][2],a[i][3]});
			if(fi[i].num==a[i][1]) fi[i].id=1;
			else if(fi[i].num==a[i][2]) fi[i].id=2;
			else fi[i].id=3;
			th[i].num=min({a[i][1],a[i][2],a[i][3]});
			if(th[i].num==a[i][1]) th[i].id=1;
			else if(th[i].num==a[i][2]) th[i].id=2;
			else th[i].id=3;
			se[i].num=t-fi[i].num-th[i].num,se[i].id=6-fi[i].id-th[i].id;
		}
		int cnt[4]={0,0,0,0};
		for(int i=1;i<=n;i++){
			ans.push(-fi[i].num); 
			if(++cnt[fi[i].id]>n/2){
				ans.pop();
				ans.push(-fi[i].id);
			}
		}
		int t=0;
		while(ans.size()){
			t-=ans.top(),ans.pop();
		}
		cout<<t<<endl;
	}	
	return 0;
}
