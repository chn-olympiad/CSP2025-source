#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m;
	cin>>n>>m;	
	int all=n*m;
	vector<int> s(all);
	int a=0;
	cin>>s[a];
	int fc=s[a];
	for(int i=1;i<all;i++)
	{
		cin>>s[i];
	}
	sort(s.begin(),s.end());
	int ans=0;
	for(int i=all;i>=0;i--)
	{
		if(s[i]==fc) 
		{
			ans=all-i;
			break;
		}
	}
	int c=0;
	int d=ans%n;
	if(d!=0)  c=ans/n+1;
	else  c=ans/n;
	int r=0;
	if(c==1)  r=ans;
	else if(c%2!=0 && c!=1)  r=ans%c;
	else if(c%2==0)  r=n-(ans-n*c);
	cout<<ans<<endl;;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
