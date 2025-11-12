#include <bits/stdc++.h>
using namespace std;
const int N=550;
int n,m,k,c[N],a[N];
string s;
bool cmp(int x,int y){
	return x<y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		int x;
		scnaf("%d",&x);
		if(x!=0)c[i]=x;
	}
	int len=c.length;
	sort(c+1,c+1+len,cmp);
	for (int i=0;i<n;i++)
	{
		a[i+1]=s[i]-'0';
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
}
