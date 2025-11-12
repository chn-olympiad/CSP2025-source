#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,cc=0;
    cin>>t;
    int c[t]={0};
    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        int mar=n/2,aa1=0,aa2=0,aa3=0;

        int a[n][3]={0};

        int a1[n]={0};
        int a2[n]={0};
        int a3[n]={0};

        for(int h=0;h<n;h++){
            for(int l=0;l<3;l++){
                cin>>a[h][l];
            }
        }

        for(int l=0;l<n;l++){
                int m=0,b;
            for(int z=0;z<3;z++){
                if(m<a[l][z]){
                    m=a[l][z];
                    b=z;
                }
            }
            if(b==2){
                a3[aa3]=m;
                aa3++;
            }
            else if(b==1){
                a2[aa2]=m;
                aa2++;
            }
            else{
                a1[aa1]=m;
                aa1++;
            }

        }
        for(int ii=0;ii<aa1;ii++){
            for(int ll=ii+1;ll<aa1;ll++){
                if(a1[ii]<a1[ll]){
                    swap(a1[ll],a1[ii]);
                }
            }
        }
        for(int ii=0;ii<aa2;ii++){
            for(int ll=ii+1;ll<aa2;ll++){
                if(a2[ii]<a2[ll]){
                    swap(a2[ll],a2[ii]);
                }
            }
        }
        for(int ii=0;ii<aa3;ii++){
            for(int ll=ii+1;ll<aa3;ll++){
                if(a3[ii]<a3[ll]){
                    swap(a3[ll],a3[ii]);
                }
            }
        }
        int ans=0;
        for(int xx=0;xx<n/2;xx++){
            ans+=a1[xx];
            ans+=a2[xx];
            ans+=a3[xx];
        }
        c[cc]=ans;
        cc++;
    }
    for(int i=0;i<t;i++){
        cout<<c[i]<<endl;
    }

    return 0;
}
