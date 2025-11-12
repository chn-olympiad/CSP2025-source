#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number2.in","r",stdin);
    freopen("number2.out","w",stdout);
    int n;
    char a[n];
    cin >>n;
    for(int i=0;i<=n;i++)
    {
    	cin >> a[i];
    	if((a[i]='1')||(a[i]='2')||(a[i]='0')||(a[i]='4')||(a[i]='5')||(a[i]='6')||(a[i]='7')||(a[i]='8')||(a[i]='9'))
        {
            cout << a[i];
            break;
        }
	}
    return 0;
}




















































































































































