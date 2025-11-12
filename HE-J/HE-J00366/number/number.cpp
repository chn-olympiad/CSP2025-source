#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c[100005];
	cin>>c;
	for(int i=0;i<100;i++)
	{
		if(c[i]>='48'&&c[i]<='57'&&c[i]<c[i+1])
		{
			c[i]=c[i+1];
		}
	}
	cout<<c[100005];
	return 0;
}
