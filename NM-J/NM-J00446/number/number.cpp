#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int c=0;
bool bmp(int a,int b)
{
	return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=1;i<=l;i++)
    {
        if((s[i]>='0')&&(s[i]<='9')) {a[i]=s[i];c++;}
    }
    sort(a+1,a+l+1,bmp);
    for(int i=1;i<=c-1;i++)
        cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
