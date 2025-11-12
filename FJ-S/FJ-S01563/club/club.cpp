#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
const int MAXN=1e5+5;
int n,a[MAXN][4];
int num[4];

char gc(){return getchar();}
void pc(char c){putchar(c);}

void read(int &x){
	char c; bool f=false;
	for(;!isdigit(c=getchar());)
		if(c=='-') f=true;
	for(x=c-'0';isdigit(c=getchar());)
		x=x*10+c-'0';
	if(f) x=-x;
}

void write(int x){
	if(x==0){pc('0');return;}
	if(x<0){pc('-');x=-x;}
	char s[20]; int k=0;
	for(;x;x/=10) s[k++]=x%10+'0';
	for(;k--;) pc(s[k]);
}

void input(){
	read(n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j) read(a[i][j]);
	}
}

bool checkA(){
	for(int i=1;i<=n;++i){
		if(a[i][2]!=0) return false;
		if(a[i][3]!=0) return false;
	}
	return true;
}

void solveA(){//5pts
	int ans=0;
	vector<int> ve;
	for(int i=1;i<=n;++i) ve.push_back(a[i][1]);
	sort(ve.begin(),ve.end(),greater<int>());
	for(int i=0;i<n/2;++i) ans+=ve[i]; 
	write(ans);
}

bool checkB(){
	for(int i=1;i<=n;++i){
		if(a[i][3]!=0) return false;
	}
	return true;
}

void solveB(){//15pts
	int ans=0;
	vector<pii> ve;
	for(int i=1;i<=n;++i) ve.push_back({a[i][1],a[i][2]});
	sort(ve.begin(),ve.end(),[](pii a,pii b){
		return a.first-a.second>b.first-b.second;
	});
	for(int i=0;i<n/2;++i) ans+=ve[i].first;
	for(int i=n/2;i<n;++i) ans+=ve[i].second;
	write(ans);
}

void dfs(int i,int sum,int &ans){
	ans=max(ans,sum);
	if(i==n+1) return;
	for(int j=1;j<=3;++j){
		if(++num[j]<=n/2) dfs(i+1,sum+a[i][j],ans);
		--num[j];
	}
}

void baoli(){//20~40pts
	int ans=0;
	dfs(1,0,ans);
	write(ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	for(read(t);t--;){
		input();
		if(checkA()) solveA();
		else if(checkB()) solveB();
		else baoli();
		pc('\n');
	}
	return 0;
}
