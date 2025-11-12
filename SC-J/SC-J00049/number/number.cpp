#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    
    for (int i=0;i<a.length()-1;i++)
    {
    	 for (int j=i+1;j<a.length();j++)
    	 {
    	 	if(a[i]<a[j])
			{
			 	swap(a[i],a[j]);
			}
		 }
	}
    cout<<a;
    return 0;
}