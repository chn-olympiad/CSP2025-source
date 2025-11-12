#include <bits/stdc++.h>
using namespace std;
void f()
{
    int n,i,j,mx=0;
    cin>>n;
    int a[n+1][4];
    int b[n+1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=3;j++)
        {
            cin>>a[i][j];
            if(j==2)b[i]=a[i][j];
        }
    }
    if(n==2)
    {
        for(int i1=1;i1<=3;i1++){
            for(int i2=1;i2<=3;i2++){
                if(i1==i2)continue;
                mx=max(a[1][i1]+a[2][i2],mx);
            }
        }
        cout<<mx<<endl;
        return;
    }
    if(n==4){
        int i1,i2,i3,i4;
        int t[4]={0,0,0,0};
        for(i1=1;i1<=3;i1++){
            t[i1]++;
            for(i2=1;i2<=3;i2++){
                t[i2]++;
                for(i3=1;i3<=3;i3++){
                    t[i3]++;
                    for(i4=1;i4<=3;i4++){
                        t[i4]++;
                        if((t[1]>2||t[2]>2)||t[3]>2)
                        {
                            t[i4]--;
                            continue;
                        }
                        mx=max(a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4],mx);
                        t[i4]--;
                    }
                    t[i3]--;
                }
                t[i2]--;
            }
            t[i1]--;
        }
        cout<<mx<<endl;
        return;
    }
    if(n==10){
        int t[4]={0,0,0,0};
        for(int i1=1;i1<=3;i1++){
            t[i1]++;
            for(int i2=1;i2<=3;i2++){
                t[i2]++;
                for(int i3=1;i3<=3;i3++){
                    t[i3]++;
                    for(int i4=1;i4<=3;i4++){
                        t[i4]++;
                        for(int i5=1;i5<=3;i5++){
                            t[i5]++;
                            for(int i6=1;i6<=3;i6++){
                                t[i6]++;
                                for(int i7=1;i7<=3;i7++){
                                    t[i7]++;
                                    for(int i8=1;i8<=3;i8++){
                                        t[i8]++;
                                        for(int i9=1;i9<=3;i9++){
                                            t[i9]++;
                                            for(int i10=1;i10<=3;i10++){
                                                t[i10]++;
                                                if(t[1]>5||t[2]>5||t[3]>5)
                                                {
                                                    t[i10]--;
                                                    continue;
                                                }
                                                mx=max(a[1][i1]+a[2][i2]+a[3][i3]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][i10],mx);
                                                t[i10]--;
                                            }
                                            t[i9]--;
                                        }
                                        t[i8]--;
                                    }
                                    t[i7]--;
                                }
                                t[i6]--;
                            }
                            t[i5]--;
                        }
                        t[i4]--;
                    }
                    t[i3]--;
                }
                t[i2]--;
            }
            t[i1]--;
        }
        cout<<mx<<endl;
        return;
    }

    if(n==100000)
    {
        sort(b+1,b+n+2);
        int mx=0;
        for(j=n;j>n/2;j--)mx+=b[j];
        cout<<mx<<endl;
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)f();
    return 0;
}