#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=10086;
int a;
int tong1[500005],tong2[500005];
struct dictionary{
	string p,q;
	int derta;
} t[200005],st,ed;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].p>>t[i].q;
		int j=0;
		while(t[i].p[j]=='a') j++;
		t[i].derta=j;
		j=0;
		while(t[i].q[j]=='a') j++;
		t[i].derta-=j;
		if(t[i].derta<0) tong1[-t[i].derta]++;
		else tong2[t[i].derta]++;
	}
	for(int i=1;i<=m;i++)
	{
		string x,y;
		int xl;
		cin>>x>>y;
		int j=0;
		while(x[j]=='a') j++;
		xl=j;
		j=0;
		while(y[j]=='a') j++;
		xl-=j;
		if(xl<0)
			cout<<tong1[-xl];
		else cout<<tong2[xl];
		cout<<endl;
	}
	return 0;
}