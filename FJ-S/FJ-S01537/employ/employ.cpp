#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Code ios::sync_with_stdio(0);
#define with cin.tie(0);
#define ZhouShen cout.tie(0);
#define int long long
using namespace std;
int n,m,t;
string s;
void read(int&a){
	int s=0,w=1;
	char ch;
	ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-')w=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	a=s*w;
}
int A(int x){
	int sum=1;
	for(int i=1;i<=x;i++){
		sum=sum*i%998244353;
	}
	return sum;
}
signed main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	Code with ZhouShen
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>t;
		if(t==0)n--;
	}
	if(n<m)cout<<0;
	else cout<<A(n);
	return 0;
}
