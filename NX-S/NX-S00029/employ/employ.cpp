#include <bits/stdc++.h>
using namespace std;
long long n,m,nd[505],c[505],ans=0,s=0,v=0;
string p;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>p;
    for(int i=0;i<p.size();i++) nd[i]=p[i]-'0';
    for(int i=1;i<=n;i++) if(nd[i]==1) s++;
    if(s==n)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i1=1;i1<=n;i1++)
    {
        for(int i2=1;i2<=n;i2++)
        {
            for(int i3=1;i3<=n;i3++)
            {
                for(int i4=1;i4<=n;i4++)
                {
                    for(int i5=1;i5<=n;i5++)
                    {
                        for(int i6=1;i6<=n;i6++)
                        {
                            for(int i7=1;i7<=n;i7++)
                            {
                                for(int i8=1;i8<=n;i8++)
                                {
                                    for(int i9=1;i9<=n;i9++)
                                    {
                                        for(int i10=1;i10<=n;i10++)
                                        {
                                            v=0;
                                            if(i1!=i2 && i1!=i3 &&i1!=i4&&i1!=i5 && i1!=i6 &&i1!=i7&&i1!=i8 && i1!=i9 &&i2!=i3&&i2!=i4&&i2!=i5&&i2!=i6&&i2!=i7&&i2!=i8&&i2!=i9&&i3!=i4&&i3!=i5&&i3!=i6&&i3!=i7)
                                            {
                                                if(i3!=i8&&i3!=i9&&i4!=i5&&i4!=i6&&i4!=i7&&i4!=i8&&i4!=i9&&i5!=i6&&i5!=i7&&i5!=i8&&i5!=i9)
                                                {
                                                    if(i6!=i7&&i6!=i8&&i6!=i9&&i7!=i8&&i7!=i9&&i8!=i9)
                                                    {
                                                        if(i1!=i10&&i2!=i10&&i3!=i10&&i4!=i10&&i5!=i10&&i6!=i10&&i7!=i10&&i8!=i10&&i9!=i10)
                                                        {
                                                            if(nd[i1]==0&&i1<c[1])v++;
                                                            if(nd[i2]==0&&i2<c[2])v++;
                                                            if(nd[i3]==0&&i3<c[3])v++;
                                                            if(nd[i4]==0&&i4<c[4])v++;
                                                            if(nd[i5]==0&&i5<c[5])v++;
                                                            if(nd[i6]==0&&i6<c[6])v++;
                                                            if(nd[i7]==0&&i7<c[7])v++;
                                                            if(nd[i8]==0&&i8<c[8])v++;
                                                            if(nd[i9]==0&&i9<c[9])v++;
                                                            if(nd[i10]==0&&i10<c[10])v++;
                                                        }
                                                    }
                                                }
                                            }
                                            if(v>=m) ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
}
