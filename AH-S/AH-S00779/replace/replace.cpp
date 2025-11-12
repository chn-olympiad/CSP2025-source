#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n, m, T, ans, k, dp[N][4], a[N], t[4], b[N], c[N];
vector<int> e[N];
int read(){
	int s=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
map<string, string> mp;
pair<string, string> p[N];
bool cmp(int a, int b){return a>b;}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n=read();
	m=read();
	for(int i=1; i<=n; i++){
		string s1, s2;
		cin>>s1>>s2;
		p[i]=make_pair(s1, s2);
	}
	for(int i=1; i<=m; i++){
		string s1, s2;
		int ans=0;
		cin>>s1>>s2;
		int st=0, et=0;
		for(int i=0; i<s1.size(); i++){
			if(st){
				if(s1[i]==s2[i]) et=i-1;
				break;
			}
			else if(s1[i]!=s2[i]&&!et) st=i;
		}
		for(int i=1; i<=n; i++) if(make_pair(s1.substr(st, et), s2.substr(st, et))==p[i]) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
