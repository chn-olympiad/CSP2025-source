#include<bits/stdc++.h>
#define int long long
#define N 1000006
using namespace std;

#define gc getchar()
void read(int &n){int l=1,num=0;char ch;
while(ch=gc,ch<'0'||ch>'9')if(ch=='-')
l=-1;num=ch-'0';while(ch=gc,ch<='9'&&ch>='0')
num=num*10+ch-'0';n=l*num;return;}

string s;int n,a[N];
bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;for(int i=0;i<s.length();i++)if(s[i]<='9'&&s[i]>='0')a[++n]=s[i]-'0';
	sort(a+1,a+n+1,cmp);for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}

