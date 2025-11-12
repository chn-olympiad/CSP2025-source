#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int t=0,len;
	cin>>s;
	len=s.size();
	for(int i=1;i<=len;i++)
	{
		if(i=='0'||i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='6'||i=='7'||i=='8'||i=='9')
		t++;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

