#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(long long i=a;i<=b;i++) 
#define dlp(i,a,b) for(long long i=a;i>=b;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb push_back
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int MAXN=1e6+5;
int k[12],txt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	ulp(i,0,s.size()-1){
		if('0'<=s[i]&&s[i]<='9'){
			++k[int(s[i]-48)];
		}
	}
	dlp(i,9,0){
		ulp(j,1,k[i])cout<<i;
	}
}
