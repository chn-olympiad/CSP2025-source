#include<bits/stdc++.h>
using namespace std;
string op;
long long sdx[1000006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>op;
	int m=op.size();
	for(int i=0;i<=m+1;i++)
	{
		if(op[i]=='9') sdx[9]++;
		if(op[i]=='8') sdx[8]++;
		if(op[i]=='7') sdx[7]++;
		if(op[i]=='6') sdx[6]++;
		if(op[i]=='5') sdx[5]++;
		if(op[i]=='4') sdx[4]++;
		if(op[i]=='3') sdx[3]++;
		if(op[i]=='2') sdx[2]++;
		if(op[i]=='1') sdx[1]++;
		if(op[i]=='0') sdx[0]++;
    }
    
	
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=sdx[i];j++)
		{
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
