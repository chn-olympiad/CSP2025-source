#include<bits/stdc++.h>
using namespace std;
string a;
long long n[100005];
long long str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
    	if(a[i]>='0'&&a[i]<='9')
    	{
    		str++;
    		n[str]=int(a[i]-48);
		}
	}
    sort(n+1,n+str+1);
	for(long long i=str;i>=1;i--)
	{
		cout<<n[i];
	 } 
	return 0;
} 
