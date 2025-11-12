//暴力枚举 
#include<bits/stdc++.h> 
using namespace std;
int n,m,a[505],c[505],s;
string st;
bool df[505];
void renshu()
{
	int t,wlq;
	for(int i=1;i<=n;i++)
	{
		
	}
}
void dfs(int ab,int bb,int ssss)
{
	//cout<<ab<<" "<<bb<<endl; 
	cout<<ssss<<endl;
	swap(c[ab],c[bb]);
	if(ssss>n) return ;
	for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<" "; 
	}cout<<endl;
	for(int i=bb+1;i<=n;i++)
	{
		dfs(bb,i,ssss+1);
	}
}
int tongji()//统计 
{
	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for(int i=0;i<st.size();i++)
	{
		a[i+1]=st[i]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	return 0;
 } 
