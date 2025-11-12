#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,bj[5005],cnt,maxs;
stack<int>s,s1;
void f(int x,int y,int z)
{
    if(x==y)
    {
        if(sum>=maxs*2)
        {
//            while(s.size())
//            {
//                s1.push(s.top());
//                cout<<s.top()<<" ";
//                s.pop();
//            }
//            while(s1.size())
//            {
//                s.push(s1.top());
//                s1.pop();
//            }
//            cout<<endl;
            cnt++;
        }
        return ;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(bj[i]==0)
            {
                s.push(a[i]);

                sum+=a[i];
                int maxx=maxs;
                maxs=max(maxs,a[i]);
                bj[i]=1;
                f(x+1,y,z);
                maxs=maxx;
                s.pop();
                bj[i]=0;
                sum-=a[i];
            }

        }
    }
}
int main()
{
//    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
//        int sum=a[i];
//        for(int j=1;j<=i;j++)
//        {
//            if(f)
//        }
        s.push(a[i]);
        f(1,3,a[i]);
    }
    cout<<cnt;
    return 0;
}
