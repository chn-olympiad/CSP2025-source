#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

int a[MAX]={0};

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t=0;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n=0;
        int ans=0;
        int rubbish=0;
        int rubbish1=0;

        for(int j=0;j<n;j++)
            cin>>a[i]>>rubbish>>rubbish1;

        sort(a,a+n,cmp);

        for(int i=0;i<n/2;i++)
            ans+=a[i];

        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

/*
bool cmp(freshman a,freshman b){
    return max(a.m)>max(b.m);
}

void sor()
{

}

struct freshman{
    int a1;
    int a2;
    int a3;
    int m;
    int num;
};

freshman a[MAX]={0};

int main()
{
    int t=0;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        int n=0;
        int door1=0;
        int door2=0;
        int door3=0;

        cin>>n;

        for(int j=0;j<n;j++)
        {
            cin>>a[j].a1>>a[j].a2>>a[j].a3;
        }

        sort(a,a+n,cmp);

        for(int j=0;j<n;j++)
        {
            if()
        }
    }

    return 0;
}*/
