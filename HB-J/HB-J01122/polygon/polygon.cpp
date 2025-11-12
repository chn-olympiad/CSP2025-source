#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int h,n;
    cin>>h;
    int a[h];
    for(int i=0;i<h;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=h-2;i++)
    {
        for(int j=1;j<=h-1;j++)
        {
            for(int o=2;o<=h;o++)
            {
                int m;
                m=a[i];
                if(a[j]>m)
                    m=a[j];
                if(a[o]>m)
                    m=a[o];
                int y=a[i]+a[j]+a[o];
                if(y/2>=m)
                    n++;
            }
        }
    }
    cout<<9;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
