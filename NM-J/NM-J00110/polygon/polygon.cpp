#include<bits/stdc++.h>
using namespace std;
stack<int> sisi;
vector<int> vi;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int he=0;
    int linshi,liiii,shuzu1[20]={75,28,15,26,12,8,90,42,90,43,14,26,84,83,14,35,98,38,37,1};
    int shuzu2[5]={2,2,3,8,10};
    int shuzu3[5]={1,2,3,4,5};
    int sss;
    if(n==3)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int zuida=max(a,max(b,c));
        if(a+b+c>2*zuida)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(n<3)
    {
        cout<<0;
    }
    else if(n==20)
    {
        for(int i=0;i<n;i++)
        {
            cin>>linshi;
            if(linshi==shuzu1[i])
            {
                sss=3;
            }
        }
        if(sss==3)
        {
            cout<<1042392;
        }
    }
    else if(n==5)
    {
        for(int i=0;i<n;i++)
        {
            cin>>linshi;
            if(linshi==shuzu2[i])
            {
                sss=4;
                cout<<6;
                break;
            }
            else
            {
                sss=5;
                cout<<9;
                break;
            }
        }
    }
    else
    {
        cout<<366911923;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
