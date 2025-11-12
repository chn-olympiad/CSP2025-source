#include<bits/stdc++.h>
using namespace std;
int v[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string st;cin>>st;
	int k=0;
	for(int i=0;i<st.size();i++)if(isdigit(st[i]))++k,v[k]=st[i]-'0';
	sort(v+1,v+k+1);
	for(int i=k;i>=1;i--)cout<<v[i];
} 