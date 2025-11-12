#include<bits/stdc++.h>
#define long long
using namespace std;

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int iii=1;iii<=T;iii++){
    int n;
    cin>>n;


    int a[n+1][4];
    int st[n+1][5];
    //vector<vector<int> > m1[n+1][2],m2[n+1][2],
    int m[4][n+1][3];
    //int m1r=0,m2r=0,m3r=0;
    int ml[4][3];
    for(int i=1;i<=3;i++){
        ml[i][1]=0;
        ml[i][2]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }

        int xpc=0,xpcm=0;

        if(a[i][1]>a[i][2]){
            xpc=a[i][1];
            xpcm=1;
        }
        else{
            xpc=a[i][2];
            xpcm=2;
        }

        if(a[i][3]>xpc){
            st[i][1]=3;
            st[i][2]=a[i][3];
            st[i][3]=xpcm;
            st[i][4]=xpc;

            m[3][i][1]=a[i][3];
            m[3][i][2]=i;
            ml[3][1]++;
            ml[3][2]+=a[i][3];
        }
        else{
            st[i][1]=xpcm;
            st[i][2]=xpc;
            m[xpcm][i][1]=a[i][xpcm];
            m[xpcm][i][2]=i;
            ml[xpcm][1]++;
            ml[xpcm][2]+=xpc;
            if(xpcm==1){
                if(a[i][3]>a[i][2]){
                    st[i][3]=3;
                    st[i][4]=a[i][3];
                }
                else{
                    st[i][3]=2;
                    st[i][4]=a[i][2];
                }
            }
            else{
                if(a[i][3]>a[i][1]){
                    st[i][3]=3;
                    st[i][4]=a[i][3];
                }
                else{
                    st[i][3]=1;
                    st[i][4]=a[i][1];
                }
            }


            //st[i][1]=xqc;
            //st[i][2]=max(a[i][3],min(a[i][1],a[i][2]));
        }
        //st[i][5]=i;
    }

    for(int i=1;i<=3;i++){
        if(ml[i][1]>(n/2)){

            int zb1=0,zb2=0;
            for(int i2=2;i2<=ml[i][1];i2++){
                for(int j=i2;j>1;j--){
                    if(m[i][j][1]>m[i][j-1][1]){
                        zb1=m[i][j-1][1];
                        m[i][j-1][1]=m[i][j-1][1];
                        m[i][j][1]=zb1;
                        zb2=m[i][j-1][2];
                        m[i][j-1][1]=m[i][j-1][2];
                        m[i][j][2]=zb2;
                    }
                }
            }

            for(int j=ml[i][1];j>(n/2);j--){
                if(i==st[m[i][j][2]][1]){
                    ml[i][2]-=st[m[i][j][2]][2];
                    ml[st[m[i][j][2]][3]][2]+=st[m[i][j][2]][4];
                }
                else if(i==st[m[i][j][2]][3]){
                    ml[i][2]-=st[m[i][j][2]][4];
                    ml[st[m[i][j][2]][1]][2]+=st[m[i][j][2]][2];
                }
                else{
                    ml[i][2]-=min(a[m[i][j][2]][1],min(a[m[i][j][2]][2],a[m[i][j][2]][3]));
                    ml[st[m[i][j][2]][1]][2]+=st[m[i][j][2]][2];
                }
            }

        }
    }


    //cout<<m[1][1][1]<<" "<<m[1][2][1]<<endl;




    int ans=ml[1][2]+ml[2][2]+ml[3][2];
    cout<<ans<<endl;

    }

    return 0;
}
