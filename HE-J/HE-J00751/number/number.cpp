#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,c;
	int n,i,j=0,b[15]={0};
	char s;
	while(cin>>s)
	{
		if(s>='0'&&s<='9')b[s-'0']++;
	}
    for(i=9;i>=0;i--)
    	for(j=b[i];j>0;j--)
    	cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}//#Shang4Shan3Ruo6Shui4
