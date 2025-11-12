#include<bits/stdc++.h>
#define rp(i,a,b) for(int i=a;i<=b;i++)
#define pr(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

string s;
int x,n[1000001];
int main(){
	freopen("number.in",r,stdin);
	freopen("number.out",w,stdout);
	cin>>s;
	rp(i,0,s.size()-1)if(s[i]>='0'&&s[i]<='9')n[++x]=s[i]-'0';
	sort(n+1,n+x+1,greater<int>());
	rp(i,1,x)cout<<n[i];
	return 0;
}

//I love ¡é¡é¡ê

//ÓÚ8:51Íê³É 
