#include <bits/stdc++.h>
using namespace std;
int n,t,x,y,z,a[100007],b[100007],c[100007],d[100007],c1,c2,c3,sum,fla;
map<int,int> mp,mp2,mp3;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=0;
        mp.clear();mp2.clear();mp3.clear();
        for(int i=1;i<=n;i++)
        {
            cin >> x >> y >> z;
            a[i]=x;
            b[i]=y;
            c[i]=z;
            if(y||z) fla=1;
            sum+=max(x,max(y,z));
            if(x>y&&x>z) d[i]=1,c1++;
            if(y>x&&y>z) d[i]=2,c2++;
            if(z>x&&z>y) d[i]=3,c3++;
        }
        if(fla==0)
        {
            sum=0;
            sort(a+1,a+n+1,greater<int>());
            for(int i=1;i<=n/2;i++) sum+=a[i];
            cout << sum;
            continue;
        }
        if(c1>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(d[i]==1) mp[i]=(a[i]-max(b[i],c[i]))*10+i;
            }
            for(int i=1;i<=n/2;i++)
            {
                sum-=mp[i]/10;
                mp2[mp[i]%10]=b[mp[i]%10]-max(a[mp[i]%10],c[mp[i]%10]);
                c2++;
                //cout << mp[i] << " ";
            }
        }
        //cout << " mp1\n";
        if(c2>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(d[i]==2) mp2[i]=b[i]-max(a[i],c[i]);
            }
            for(int i=1;i<=n/2;i++)
            {
                sum-=mp2[i]/10;
                mp3[mp2[i]%10]=b[mp2[i]%10]-max(a[mp2[i]%10],c[mp2[i]%10]);
                c3++;
                //cout << mp2[i] << " ";
            }
        }
        //cout << " mp2\n";
        if(c3>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(d[i]==3) mp3[i]=c[i]-max(a[i],b[i]);
            }
            for(int i=1;i<=n/2;i++)
            {
                sum-=mp3[i];
                //cout << mp3[i] << " ";
            }
        }
        //cout << " mp3\n";
        cout << sum << "\n";//<< "\n\n\n\n---";
    }
    return 0;
}
