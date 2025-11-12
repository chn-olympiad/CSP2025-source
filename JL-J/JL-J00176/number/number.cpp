#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int a1[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int b,j1=0,l=0,q=1;
    while(q)
    {
        cin>>a[l];
        l++;
        if(a[l]>=0 or a[l]<=9)
        {
            a1[j1]=a[l];
            j1++;
        }
        if(a[l]=='/n'){
            q--;
        }
    }
    for(int i=j1;i<0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(a1[j]>a1[j+1])
            {
                l=a1[j];
                a1[j]=a1[j+1];
                a1[j+1]=l;
            }
        }
    }
    for(int i=0;i<j1;i++)
    {
        cout<<a1[i];
    }

return 0;
}
