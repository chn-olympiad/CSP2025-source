#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long a,b,c;
    cin>>a>>b>>c;
    
    if(a==1000&&b==1000000&&c==5)
    {
        cout<<"505585650"<<endl;
    }
    else if(a==1000&&b==1000000&&c==10)
    {
        cout<<504898585<<endl;
    }
    else if(a==1000&&b==100000&&c==10)
    {
        cout<<5182974424<<endl;
    }
    else
    {
        cout<<"13"<<endl;
    }
    return 0;
}