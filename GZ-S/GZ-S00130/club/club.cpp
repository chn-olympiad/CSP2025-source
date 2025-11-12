//GZ-S00130 贵阳市第一中学  孙乙洋
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=5e4;
int T,n,ha;
ll ans;
struct node{
	int num,id;
}a[4];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		int cnt[4]={};
		priority_queue<int>q1,q2,q3;
		cin>>n;
		ha=n>>1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[j].num,a[j].id=j;
			sort(a+1,a+4,cmp);
			int id=a[1].id,num1=M-(a[1].num-a[2].num);
			ans+=a[1].num,cnt[id]++;
			if(id==1) q1.push(num1);
			if(id==2) q2.push(num1);
			if(id==3) q3.push(num1);
			if(cnt[id]>ha){
				if(id==1) ans-=(M-q1.top()),q1.pop();
				if(id==2) ans-=(M-q2.top()),q2.pop();
				if(id==3) ans-=(M-q3.top()),q3.pop();
				cnt[id]--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
