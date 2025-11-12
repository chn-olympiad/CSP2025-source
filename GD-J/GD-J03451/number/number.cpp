#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005],m;
int n;
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[++m]=s[i]-48;
		}
	}
	sort(a+1,a+m+1,cmp);
	if(a[1]==0){
		cout << 0;
		return 0; 
	}
	for(int i=1;i<=m;i++)
	{
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
