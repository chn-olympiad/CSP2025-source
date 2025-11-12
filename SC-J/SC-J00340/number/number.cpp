#include <iostream>
#include <algorithm>
using namespace std;
//24分，不划算也得受着捏 
int a[11],x,s;
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	//思路：转数组再排序 
	int b[1000001];
	cin>>s;//嗯，我忘了str转int怎么写了。
	for(int i=1;s>=1;i++)
	{
		b[i]=s%10;
		s/=10;
		x++;
	}
	for (int i=1;i<=x;i++)//计数排序 
	{
		a[b[i]]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}