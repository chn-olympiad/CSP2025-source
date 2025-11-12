#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N][3],sum;
vector<int > v[3];
void solve(){
	scanf("%d",&n);
	sum=0;
	for(int o=0;o<3;o++) v[o].clear();
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]),mx=max(mx,a[i][j]);
		for(int j=0;j<3;j++){
			if(a[i][j]==mx){
				v[j].push_back(i);
				break;
			}
		}
		sum+=mx;
	}
	int op=-1;
	for(int o=0;o<3;o++)
		if((int)v[o].size()>n/2) op=o;
	if(op==-1){
		printf("%d\n",sum);
		return;
	}
	vector<int > s;
	for(int x:v[op]){
		int val=1e9;
		for(int o=0;o<3;o++)
			if(o!=op) val=min(val,a[x][op]-a[x][o]);
		s.push_back(val); 
	}
	sort(s.begin(),s.end());
	int C=(int)v[op].size()-n/2;
	for(int i=0;i<C;i++) sum-=s[i];
	printf("%d\n",sum);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solve();
} 
