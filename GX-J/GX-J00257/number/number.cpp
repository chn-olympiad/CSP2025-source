#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s=" ";
	long long c,a=0,z;
	int arr[1000100]={0};
	getline(cin,s);
	z=s.size();
	for(c=0;c<z;c++)
	{
		if(s[c]>='0' && s[c]<='9')
		{
			arr[a]=s[c]-'0';
			a++;
		}
	}
	sort(arr+0,arr+a);
	for(c=a-1;c>=0;c--)
	cout<<arr[c];
		
	
	return 0;
}
