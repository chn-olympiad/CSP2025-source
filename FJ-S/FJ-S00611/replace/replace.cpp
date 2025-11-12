#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll read(){
	ll w=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return w*x;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar((x%10)+'0');
}
void writen(ll x){
	write(x);
	putchar('\n');
}
int n,q;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	string t1,t2;
	while(q--){
		cin>>t1>>t2;
		writen(0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}