#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int d[1000010];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int r=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            d[r]=a[i]-'0';
            r++;
        }
    }
    sort(d,d+r);
    for(int i=r-1;i>=0;i--)
    {
        cout<<d[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
