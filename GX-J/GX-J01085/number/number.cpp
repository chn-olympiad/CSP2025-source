#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    char z[1000001]={};
    int s=0;
    cin>>a;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            z[s]=a[i];
            s+=1;
        }
    }
    for(int n=0;n<s;n++)
    {
        for(int m=0;m<s;m++)
        {
            if(z[m]>z[m+1])
            {
                int p=z[m];
                z[m]=z[m+1];
                z[m+1]=p;
            }
        }
    }
    for(int h=s;h>0;h--)
    {
        cout<<z[h];
    }




    return 0;
}
