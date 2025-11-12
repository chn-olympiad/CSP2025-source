#include<bits/stdc++.h>
#define ll long long

using namespace std;
void read(int &x){
	char c=getchar();x=0;
	int fh=1;
	while(c<'0'||'9'<c){
		if(c=='-') fh=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') x=x*10+c-48,c=getchar();
	x*=fh;
}
void write(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>=10) write(x/10);
	putchar((char)(x%10+48));
}
const int N=1e6+5;
int n,len,a[N];
string s;
bool cmp(int x,int y) {
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++) {
		if(s[i]>='0'&&s[i]<='9') a[++n]=s[i]-48;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)putchar((char)(a[i]+48));
	return 0;
}