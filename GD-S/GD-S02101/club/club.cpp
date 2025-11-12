#include <iostream>
#include <queue>
using namespace std;

const int MAXN=1e5+5;

int t,n,tb,tc,ans1,ans2,ans3,tneed;

int a[MAXN][5];

bool has[MAXN];

struct Data{
	int id,val;
	bool operator <(const Data &temp) const{
		return temp.val>val;
	}
};

priority_queue <Data> Q1,Q2;

int getans(int &ans,int type){
	tb=0;
	tc=0;
	tneed=n/2;
	
	while (!Q1.empty()){
		Q1.pop();
	}
	while (!Q2.empty()){
		Q2.pop();
	}
	
	for (int i=1;i<=n;i++){
		has[i]=0; 
		if (type==1){
			Q1.push({i,a[i][2]-a[i][1]});
			Q2.push({i,a[i][3]-a[i][1]});
		}
		else if (type==2){
			Q1.push({i,a[i][1]-a[i][2]});
			Q2.push({i,a[i][3]-a[i][2]});
		}
		else{
			Q1.push({i,a[i][1]-a[i][3]});
			Q2.push({i,a[i][2]-a[i][3]});
		}
	}
	
	while (tneed||!Q1.empty()||!Q2.empty()){
		while (!Q1.empty()&&has[Q1.top().id]){
			Q1.pop();
		}
		while (!Q2.empty()&&has[Q2.top().id]){
			Q2.pop();
		}
		if (Q1.empty()&&Q2.empty()){
			break;
		}
		Data t1=Q1.top();
		Data t2=Q2.top();
		if (tneed<=0&&t1.val<=0&&t2.val<=0){
			break;
		}
		if (tb<n/2&&(t1.val>=t2.val||(t1.val<t2.val&&tc>=n/2))){
			tb++;
			ans+=t1.val;
			has[t1.id]=1;
			Q1.pop();
		}
		else{
			tc++;
			ans+=t2.val;
			has[t2.id]=1;
			Q2.pop();
		}
		tneed--;
	}
	return ans;
}

void solve(){
	scanf("%d",&n);
	
	ans1=0;
	ans2=0;
	ans3=0;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		ans1+=a[i][1];
		ans2+=a[i][2];
		ans3+=a[i][3];
	}
	
	printf("%d\n",max(getans(ans1,1),max(getans(ans2,2),getans(ans3,3))));
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
