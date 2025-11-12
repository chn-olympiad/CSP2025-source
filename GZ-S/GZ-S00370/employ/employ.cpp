//GZ-S00370 遵义第四初级中学  罗若渊
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,mod=998244353,a[1000],c[1000];
bool b[10000]={0};
void qq(int now,int aa,int ss)
{
	if(now==n)
	{
	//	cout<<aa<<endl;
		if(aa>=m){//cout<<aa<<endl<<endl;
		ans++;ans%=mod;}
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			if(a[now]==0){//cout<<i<<" ";
				qq(now+1,aa,ss+1);
			}
			else if(c[i]<=ss)
			{//cout<<i<<" ";
				qq(now+1,aa,ss+1);
			} 
			else
			{//cout<<i<<" ";
				qq(now+1,aa+1,ss);
			 } 
			b[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	string h;
	cin>>h;
	for(int i=0;i<n;i++)
	{
		a[i]=h[i]-'0';
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	qq(0,0,0);
	cout<<ans;
 	return 0;	
} 
/*
Ren5Jie4Di4Ling5%

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
161088479
*/
