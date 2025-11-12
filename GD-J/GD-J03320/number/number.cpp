#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1002],j=0;
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++)
	{
		char s=n[i]-48;
		if(s<10)
		{
			a[j]=s;
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>-1;i--)cout<<a[i];
	return 0;
} 
