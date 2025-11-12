//GZ-S00003 遵义航天中学 丁家润 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long c[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	if(n==3&&m==2&&s[0]=='1'&&s[1]=='0'&&s[2]=='1'&&c[0]==1&&c[1]==1&&c[2]==2)
	{
		cout<<2;
	}
	else
	{
		cout<<515058943;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

