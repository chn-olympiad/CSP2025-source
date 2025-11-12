#include <iostream>
#include <cstring>
#include <algorithm>
const int MAXN=1000000+10;
using namespace std;
long long list[MAXN];
int main()
{
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int p=0;
	bool ifOnlyZero=true;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'){
			list[0]++;
			
		}
		if(s[i]=='1'){
			list[1]++;
			ifOnlyZero=false;
		}
		if(s[i]=='2'){
			list[2]++;ifOnlyZero=false;
		}
		if(s[i]=='3'){
			list[3]++;ifOnlyZero=false;
		}
		if(s[i]=='4'){
			list[4]++;ifOnlyZero=false;
		}
		if(s[i]=='5'){
			list[5]++;ifOnlyZero=false;
		}
		if(s[i]=='6'){
			list[6]++;ifOnlyZero=false;
		}
		if(s[i]=='7'){
			list[7]++;ifOnlyZero=false;
		}
		if(s[i]=='8'){
			list[8]++;ifOnlyZero=false;
		}
		if(s[i]=='9'){
			list[9]++;ifOnlyZero=false;
		}
	}
	if(!ifOnlyZero){
		for(int i=9;i>=0;i--)
		{
			for(int j=0;j<list[i];j++)
			{
				printf("%d",i);
			}
		}
	}
	else printf("0"); 
	return 0;
}
