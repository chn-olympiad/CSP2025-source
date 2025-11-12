#include <bits/stdc++.h>
using namespace std;
int arr[12];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sa = s.size();
	for(int i = 0;i < sa;i++)
	{
		if((s[i] - '0') >= 0 && (s[i] - '0') <= 9) arr[s[i] - '0']++;
	}
	//for(int i = 0;i <= 9;i++) cout<<"i:"<<i<<"arr[i]"<<arr[i]<<endl;//
	for(int i = 9;i >= 0;i--)
	{
		if(arr[i] != 0)
		{
			for(int j = 1;j <= arr[i];j++) cout<<i;
		}
	}
	return 0;
}






