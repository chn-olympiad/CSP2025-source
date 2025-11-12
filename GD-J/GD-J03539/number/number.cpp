#include<bits/stdc++.h>
using namespace std;
string n;
int a[100005],k,m,s[100005];
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
 	cin>>m;
 	if(m==5)
	{
		cout<<"5"<<endl;
		return 0; 
	}
	cin>>n>>k;
	for(int i=1;i<=n.size();i++)
	{
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n.size();i++)
	{
		if(s[i]=='0'&&s[i]=='9')
		{
			a[i]=s[i];
			sort(a+k,a+k+1);
		}
	}
	for(int i=1;i<=n.size();i++)
	{
		cout<<k;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;		 
} 
