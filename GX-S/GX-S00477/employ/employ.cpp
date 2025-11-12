#include<bits/stdc++.h>
using namespace std;
const int N = 505;
long long n,m;
char hard[N];
long long num[N];
long long ans,pass,nopass,Ans[N],Now = 0;
bool choose[N];
long long q[N][N];
void dfs(int per,int day,int now){
	if(per == n+1){
		if(pass >= m){
			for(int i=1;i<=n;i++){
				if(hard[i] == '0')Ans[i] = 0;
			}
			sort(Ans,Ans + n);
			int md;
			for(int i=1;i<=n;i++){
				if(Ans[i] != 0){
					md = i;
					break;
				}
			}
			if(Now == 0){
				Now++;
				for(int i=1;;i++){
					q[Now][i] = Ans[md];
					md++;
					if(md == n+1)break;
				}
			}
			else{
				for(int i=1;i<=Now;i++){
					int t = md;
					bool f = 1;
					for(int j=1;j<=m;j++){
						if(q[i][j] != Ans[t]){
							f = 0;
							break;
						}
						t++;
						if(t == n+1)break;
					}
					if(f == 0){
						continue;
					}
					else return;
				}
				Now++;
				for(int i=1;;i++){
					q[Now][i] = Ans[md];
					md++;
					if(md == n+1)break;
				}
			}
			ans++;
		}
//		for(int i=1;i<=n;i++)cout<<Ans[i]<<" ";
//		cout<<'\n';
		return;
	}
	else if(choose[now] == 0 && num[now] > nopass){
		Ans[per] = now;
		choose[now] = 1;
		if(hard[day] == '1')pass++;
		else nopass++;
		for(int i=1;i<=n;i++){
			dfs(per+1,day+1,i);
		}
		choose[now] = 0;
		if(hard[day] == '1')pass--;
		else nopass--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>hard[i];
	for(int j=1;j<=n;j++)cin>>num[j];
	pass = 0;
	nopass = 0;
	for(int i=1;i<=n;i++)choose[i] = 0;
	for(int i=1;i<=n;i++)dfs(1,1,i);
	cout<<ans<<'\n';

	return 0;
}
