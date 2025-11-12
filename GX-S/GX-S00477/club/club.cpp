#include<bits/stdc++.h>
using namespace std;
const long long N = 2*1e5 + 10;
long long t,n;
struct member{
	long long a,b,c;
}num[N];
long long ans = 0,cnt = 0;
long long cntA = 0,cntB = 0,cntC = 0;
void dfs(int i,int club){
//	cout<<"i:"<<i<<" club:"<<club<<" cnt:"<<cnt<<'\n';
//	cout<<"A:"<<cntA<<" B:"<<cntB<<" C:"<<cntC<<'\n'<<'\n';
	if(cntA == n/2+1 || cntB == n/2+1 || cntC == n/2+1)return;
	if(i == n + 1){
		if(cnt > ans)ans = cnt;
		return;
	}
	if(club == 1){
		cnt += num[i].a;
		cntA++;
	}
	else if(club == 2){
		cnt += num[i].b;
		cntB++;
	}
	else if(club == 3){
		cnt += num[i].c;
		cntC++;
	}
	for(int j=1;j<=3;j++){
		dfs(i+1,j);
		
	}
	if(club == 1){
		cnt -= num[i].a;
		cntA--;
	}
	if(club == 2){
		cnt -= num[i].b;
		cntB--;
	}
	if(club == 3){
		cnt -= num[i].c;
		cntC--;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		ans = 0;
		cnt = 0;
		cntA = 0;
		cntB = 0;
		cntC = 0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>num[j].a>>num[j].b>>num[j].c;
		}
		dfs(1,1);
		dfs(1,2);
		dfs(1,3);
		cout<<ans<<'\n';
	}

	return 0;
}
