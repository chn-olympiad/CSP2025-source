#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,p1,p2,p3,ans,lei,zhi;
int g[100005][4];
struct student{
	int d1,d2,cha;
};
student stu[100005];
bool cmp(student x,student y){
	return x.cha<y.cha;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;p1=0;p2=0;p3=0;
		for(int j=1;j<=n;j++){
			cin>>g[j][1]>>g[j][2]>>g[j][3];
			if(g[j][1]>=g[j][2]&&g[j][1]>=g[j][3]){
				p1++;
				stu[j].d1=1;
				if(g[j][2]>=g[j][3]) stu[j].d2=2;
				else stu[j].d2=3;
				stu[j].cha=g[j][1]-g[j][stu[j].d2];
			}
			else if(g[j][2]>=g[j][1]&&g[j][2]>=g[j][3]){
				p2++;
				stu[j].d1=2;
				if(g[j][1]>=g[j][3]) stu[j].d2=1;
				else stu[j].d2=3;
				stu[j].cha=g[j][2]-g[j][stu[j].d2];
			}
			else{
				p3++;
				stu[j].d1=3;
				if(g[j][2]>=g[j][1]) stu[j].d2=2;
				else stu[j].d2=1;
				stu[j].cha=g[j][3]-g[j][stu[j].d2];
			}
			ans+=g[j][stu[j].d1];
		}
		if(p1<=n/2&&p2<=n/2&&p3<=n/2){
			cout<<ans<<"\n";
			continue;
		}
		if(p1>=p2&&p1>=p3){
			lei=1;zhi=p1-n/2;
		}
		else if(p2>=p1&&p2>=p3){
			lei=2;zhi=p2-n/2;
		}
		else{
			lei=3;zhi=p3-n/2;
		}
		sort(stu+1,stu+n+1,cmp);
		for(int j=1;j<=n;j++){
			if(stu[j].d1==lei){
				ans-=stu[j].cha;
				zhi--;
			}
			if(!zhi) break;
			//cout<<stu[j].cha<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*2226147
2535425
2706555
2726734
2872395*/
