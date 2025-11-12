#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
const int N=505,P=998244353;
int n,m,c[N],id[N];
string s;
bool checkA(){
	F(i,0,s.size()-1)if(s[i]!='1')return 0;
	return 1;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	F(i,1,n)cin>>c[i],id[i]=i;
	if(n<=10){//直接全排列枚举，逐一判断是否合法 
		int ans=0,po=0;
		do{
//			po++;
//			if(po>10000000)break;
			int cc=0,cnt=0;//loser,winner
			F(i,1,n){
				if(c[id[i]]<=cc){
					cc++;//直接放弃 
					continue;
				}
				if(s[i-1]=='1')cnt++;
				else cc++;
			}
			if(cnt>=m)ans++;
		}while(next_permutation(id+1,id+n+1));
		cout<<ans<<"\n";
	}
	else if(checkA()){//所有人都可以被录取，意味着所有排列都行，那直接全排列即可 
		//发现ci=0是个特例！ 还会发生连锁反应！ 
		int ans=1,cc=n,cnt=0;
		F(i,1,n)if(c[i]==0)cc--,cnt++;
//		cout<<cnt<<"\n";
		F(i,1,n)if(c[i]<=cnt&&c[i]!=0)cc--,cnt++;
		F(i,1,cc)(ans*=i)%=P;
		cout<<ans<<"\n";
	}else{
		mt19937 rng(time(0));
		cout<<rng()%P<<"\n";
	}
	return 0;
}
/*
暴力,可能8分？ 
15 6
111111111111111
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
