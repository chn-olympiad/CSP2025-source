#include<bits/stdc++.h>
using namespace std;
string s;
int y[1000010],j=0;
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++)
	{
		if(int(s[i])<97)
		{
			j++;
			y[j]=int(s[i])-48;
		}
	}
	sort(y+1,y+j+1);
	for(;j>0;j--)cout<<y[j];
	return 0;
}