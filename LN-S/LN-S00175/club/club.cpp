#include<bits/stdc++.h>

using namespace std;
const int N=1e5+10;

int t,n;
struct student
{
    int v1,v2,v3;
    int a1,a2,b1;//di er zhi yuan de shou yi
    bool operator<(const student&wow) const
    {
        return a1-a2<wow.a1-wow.a2;
    }
}stu[N];

inline int maxxx(int v,int vv,int vvv)
{
    if(v==max(v,max(vv,vvv)))
    {
        return 1;
    }
    if(vv==max(v,max(vv,vvv)))
    {
        return 2;
    }
    return 3;
}

int bumen[5];//gai bumen li you duoshao ren

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=3;i++) bumen[i]=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>stu[i].v1>>stu[i].v2>>stu[i].v3;
            int a[3]={stu[i].v1,stu[i].v2,stu[i].v3};
            sort(a,a+3);
            stu[i].a2=a[1];// ji lu xia di er zhi yuan
            stu[i].a1=a[2];//di yi zhi yuan
            stu[i].b1=maxxx(stu[i].v1,stu[i].v2,stu[i].v3);
        }

        int ans=0;
        sort(stu+1,stu+n+1);

        //for(int i=1;i<=n;i++) cout<<stu[i].a1<<stu[i].a2<<'\n'<<stu[i].b1<<'\n';
        for(int i=1;i<=n;i++)
        {
            ans+=stu[i].a1;
            bumen[stu[i].b1]++;
        }
        //cout<<ans<<"wowow";
        //cout<<bumen[1]<<' '<<bumen[2]<<' '<<bumen[3]<<'\n'<<n<<'\n';
        if(bumen[1]>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(bumen[1]<=n/2) break;
                if(stu[i].b1==1)
                {
                    ans-=(stu[i].a1-stu[i].a2);
                    bumen[1]--;
                }
            }
        }
        else if(bumen[2]>n/2)
        {
            
            for(int i=1;i<=n;i++)
            {
                if(bumen[2]<=n/2) break;
                if(stu[i].b1==2)
                {
                    ans-=(stu[i].a1-stu[i].a2);
                    bumen[2]--;
                }
            }
        }
        else if(bumen[3]>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(bumen[3]<=n/2) break;
                if(stu[i].b1==3)
                {
                    ans-=(stu[i].a1-stu[i].a2);
                    bumen[3]--;
                }
            }
        }
        cout<<ans<<'\n';

    }
    return 0;
}
//g++ -std=c++14 -O2 wow.cpp -o c
/*
1
4
4 2 1 3 2 4 5 3 4 3 5 1
*/