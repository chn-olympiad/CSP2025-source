#include <bits/stdc++.h>
#define pa pair <int,int>
#define int long long
#define y second
#define x first
using namespace std;
const int N=2e5+10;

inline int read(){
	int ans=0;bool f=0;char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return (f?-ans:ans);
}

inline void write(int x,string s=""){
	if(x<0) x=-x,putchar('-');
	static char a[50],k=0;
	do{a[short(++k)]=x%10,x/=10;}while(x);
	while(k) putchar(a[short(k--)]|48);
	if(s=="\n") putchar('\n'); else if(s==" ") putchar(' ');
}

string s;
int vh[10];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i) if('0'<=s[i]&&s[i]<='9') vh[s[i]-'0']++;
	for(int i=9;i>=0;--i){
		for(int j=1;j<=vh[i];++j) cout<< i;
	}
	cout<< endl;
	return 0;
}
