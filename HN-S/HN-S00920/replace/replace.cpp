#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
//#define int long long
//#define int __int128
//#define int unsigned int
//#define mod
using namespace std;
void fio(string s,int i){
	freopen((s+(i?to_string(i):"")+".in").c_str(),"r",stdin);
	freopen((s+(i?to_string(i):"")+".out").c_str(),"w",stdout);
}
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}return ret*f;
}
inline void write(int x,int op=0){
	if(x<0){
		putchar('-');
		x=-x;
	}
	stack<char>qwq;
	while(!qwq.empty())qwq.pop();
	while(x>9){
		qwq.push(x%10+'0');
		x/=10;
	}
	qwq.push(x+'0');
	while(!qwq.empty())putchar(qwq.top()),qwq.pop();
	if(op>0)putchar('\n');
	if(op<0)putchar(' ');
}
int n,q;
string s[N][2];      
signed main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	return 0;
}

