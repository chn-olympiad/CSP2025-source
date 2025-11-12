#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=2e5+10;
int n,m;
string sone[maxn],stwo[maxn];
bool b[maxn];
bool check(string xx,string yy,int q){
	if(yy.size()>xx.size()-q+1)return 0;
	for(int i=0;i<yy.size();i++){
		if(xx[q+i]!=yy[i])return 0;
	}
	return 1;
}
int dfs(string x,string y,int num){
	if(num>x.size())return 1;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(b[i]==0&&check(x,sone[i],num-1)&&check(y,stwo[i],num-1)){
			
			b[i]=1;
			sum+=dfs(x,y,num+sone[i].size());
			b[i]=0;
		}
	}
	if(sum||x[num-1]==y[num-1])return sum+dfs(x,y,num+1);
	else return 0;
	/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
	*/
}
void solve1(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sone[i]>>stwo[i];
	}
	for(int i=1;i<=m;i++){
		string qone,qtwo;
		cin>>qone>>qtwo;
		cout<<dfs(qone,qtwo,1)<<"\n";
	}
}
void solve(){
	if(1)solve1();
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--)solve();
	return 0;
}
