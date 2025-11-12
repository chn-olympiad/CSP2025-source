#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={},maxx=-100;
	string s;
	cin>>s;
	int snum[n+5]={};
	for(int i=0;i<=s.size();i++)
	  snum[i+1]=s[i-1]-'0';
	for(int i=1;i<=n;i++)
	  cin>>a[i],maxx=max(maxx,a[i]);
	if(maxx==1){
		int num=0;
		for(int i=1;i<=n;i++)
		  if(snum[i]==1)
		    num++;
		  else
		    break;
		if(num<m)
		   cout<<0;
		else{
			long long cnt=0;
			for(int i=m;i>=m-num+1;i--)
			  cnt*=i;
			for(int i=num;i>=1;i--)
			  cnt/=i;
			cout<<cnt;
		}
		return 0;
	}
	else if(m==1)
	  cout<<0;
	return 0;
}

