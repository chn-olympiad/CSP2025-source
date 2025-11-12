//GZ-S00190 贵阳市第十七中学 徐廷蔚 
#include<iostream>
using namespace std;
const long long MOD=998244353;
int n,m;
string ss;
int s[505];
int c[505];

bool vis[505];
struct node{
	int id,val;
};
int ans[505];
int tot=0;
void dfs(int step){
	if(step==n+1){
		int now=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]==0){
				now++;
				continue;
			}
			if(c[ans[i]]<=now){
				now++;
				continue;
			}
			if(s[i]==1){
				cnt++;
			}
		}
		if(cnt>=m)tot++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ans[step]=i;
			dfs(step+1);
			vis[i]=0;			
		}
	}
}
int main() {

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m;
	cin>>ss;
	bool flag_1=1;
	for(int i=0; i<ss.size(); i++) {
		s[i+1]=ss[i]-'0';
		if(s[i+1]==0)flag_1=0;
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}

if(n<=10){
	dfs(1);
	cout<<tot;
}
if(flag_1==1){
	int n_=n;
//	for(int i=1;i<=n;i++){
//		if(c[i]==0)n_--;
//	}
//	int tmp=n;
//	n=n_;
//	n_=n;
	unsigned long long fengzi=1;
	for(int i=1;i<=n;i++){
		fengzi=(i*fengzi)%MOD;
	}		
//	for(int i=tmp-n;i>=1;i--){
//		fengzi+=(n_+i)*fengzi;
//	}
	fengzi%=MOD;
	cout<<fengzi;
	return 0;
}
	return 0;
}
