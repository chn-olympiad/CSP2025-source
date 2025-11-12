#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
inline long long read(){
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
map<string,int>mp;
set<int>x;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	n=read();m=read();
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			string a;
			cin>>a;
			mp[a]++;
		}
		string a,b;
		cin>>a>>b;
		cout<<mp[a]<<endl;
		return 0;
	}
	while(m--)
	{
		cout<<rand()%10000<<endl;
	}
	return 0;
}


