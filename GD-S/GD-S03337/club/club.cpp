#include<bits/stdc++.h>
using namespace std;
//注意返回值 Ren5Jie4Di4Ling5%
const int N=1e5+5;
int a[N][5];
void mian(){
	//初始化！ 
	int n;cin>>n;int s=0;
	int cnt[5]={0,0,0,0,0};
	vector<int>ch[5];//
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int mx=max({a[i][1],a[i][2],a[i][3]});
		s+=mx;
		if(a[i][1]==mx){
			cnt[1]++;
			ch[1].emplace_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
		}else if(a[i][2]==mx){
			cnt[2]++;
			ch[2].emplace_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
		}else{
			cnt[3]++;
			ch[3].emplace_back(min(a[i][3]-a[i][1],a[i][3]-a[i][2]));
		}
	}
	//因为不会同时两个满足要求
	//所以刚开始直接贪心
	if(cnt[1]<=n/2 && cnt[2]<=n/2 && cnt[3]<=n/2){
		cout<<s<<"\n";return;
	}
	//cerr<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
	//我反悔了 
	if(cnt[1]>n/2){
		sort(ch[1].begin(),ch[1].end());
		int x=cnt[1]-n/2;
		for(int i=0;i<x;i++)s-=ch[1][i];
	}else if(cnt[2]>n/2){
		sort(ch[2].begin(),ch[2].end());
		int x=cnt[2]-n/2;
		for(int i=0;i<x;i++)s-=ch[2][i];
	}else{
		sort(ch[3].begin(),ch[3].end());
		int x=cnt[3]-n/2;
		for(int i=0;i<x;i++)s-=ch[3][i];
	}
	cout<<s<<"\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
//	system("FC CLUB5.ANS CLUB5.OUT");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;while(t--)mian();
	return 0;
}
/*
14:53 over
*/
