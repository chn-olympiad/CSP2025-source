#include<bits/stdc++.h>
#define sjh0626s return
#define code 0
#define ll long long
#define PII pair<int,int>
using namespace std;
int T=1,n,res,cnt[10],idx[10];
bool use[100010];
PII a[100010][10],c[10][100010];
void change(int x){
	sort(c[x]+1,c[x]+idx[x]+1);
	for(int i=1;i<=idx[x];i++){
		if(use[c[x][i].second])continue;
		res-=c[x][i].first;
		cnt[x]--;
		use[c[x][i].second]=1;
		if(cnt[x]==n/2)break;
	}
}
void solve(){
	cin>>n;
	res=0;
	cnt[1]=cnt[2]=cnt[3]=idx[1]=idx[2]=idx[3]=0;
	for(int i=1;i<=n;i++){
		use[i]=0;
		for(int j=1;j<=3;j++){
			cin>>a[i][j].first;
			a[i][j].second=j;
		}
		sort(a[i]+1,a[i]+4,greater<PII>());
		res+=a[i][1].first;
		cnt[a[i][1].second]++;
		c[a[i][1].second][++idx[a[i][1].second]]={a[i][1].first-a[i][2].first,i};
		c[a[i][1].second][++idx[a[i][1].second]]={a[i][1].first-a[i][3].first,i};
	}//TaskB:一次判决
	//因一次判决后剩下的不会大于n/2所以直接找
	if(cnt[1]>n/2){ 
		change(1);
	}
	else if(cnt[2]>n/2){
		change(2);
	}
	else if(cnt[3]>n/2){
		change(3);
	}
	cout<<res<<"\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)solve();
	sjh0626s code;
}
/*
4
1 3
2 4
0 5
6 7
策略：
先全选最大的不管人数，然后再贪心去调

*/