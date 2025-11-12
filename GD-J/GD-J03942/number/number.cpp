#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,k[N];
string s;
int cmp(int a,int b){return a>b;}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++) k[i-1]=((s[i-1]>='0' && s[i-1]<='9')? s[i-1]-'0' : -1);
	sort(k,k+n,cmp);
	if(k[0]==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(k[i-1]==-1) break;
		cout<<k[i-1];
	}
	return 0;
}// T1 ´óÔ¼ 100pts
