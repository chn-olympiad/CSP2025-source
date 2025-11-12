#include <iostream>
using namespace std;
int n,i,j,k;
char s[1000001];
int a[1000001];
int main()
{
    cin>>s;
    for(i=0;i<1000000;i++)
    {        if(s[0]==1 || s[i]==2 || s[i]==3 || s[i]==4 || s[i]==5 || s[i]==6 || s[i]==7 || s[i]==8 || s[i]==9)
        {
            a[i]=s[i];
        }
    }
cout<<a[1]<<endl;
	return 0;
}
