#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int n,res,exd;

struct Sa{
	int id,grp,val;
	
	bool operator <(const Sa x)const{
		return val>x.val;
	}
}ori[N][3];

int nowc[3];
priority_queue<Sa>que[3];

void init(){
	for(int i=0;i<=2;i++){
		while(!que[i].empty())que[i].pop();
		nowc[i]=0;
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	
	for(;T;T--){
		cin>>n;
		init();
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				ori[i][j].grp=j;
				ori[i][j].id=i;
				cin>>ori[i][j].val;
			}
			sort(ori[i],ori[i]+3);
			res+=ori[i][0].val;
			ori[i][0].val-=ori[i][1].val;
			que[ori[i][0].grp].push(ori[i][0]);
			nowc[ori[i][0].grp]++;
		}
		exd=-1;
		for(int i=0;i<=2;i++){
			if(nowc[i]>n/2){
				exd=i;
				break;
			}
		}
		if(exd>=0){
			while(nowc[exd]>n/2){
				res-=que[exd].top().val;
				que[exd].pop();
				nowc[exd]--;
			}
		}
		cout<<res<<'\n';
		res=0;
	}
	return 0;
} 
