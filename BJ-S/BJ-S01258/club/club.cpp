#include<bits/stdc++.h>
using namespace std;
int n,a[100007][4],t,p,mm[100007][4]{},hp[1000007][3]{},pp[1000007][3]{},aa[4];
long long ans;
void stup(){

    for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            mm[i][1]=1;
            mm[i][2]=2;
            mm[i][3]=3;
            for(int j=1;j<=2;j++){
                for(int o=1;o<=2;o++){
                    if(a[i][o]<a[i][o+1]){
                        swap(a[i][o],a[i][o+1]);
                        swap(mm[i][o],mm[i][o+1]);
                    }
                }
            }
        }
}
void mgsrt1(int l,int r){
    int p,q,cntt=l;
    p=(l+r)/2;
    q=r;
    int x=l,y=((l+r)/2)+1;
    if(l!=r){
        mgsrt1(l,(l+r)/2);
        mgsrt1(((l+r)/2)+1,r);
    }
    for(int i=l;i<=r;i++){
        hp[i][1]=a[i][1];
        hp[i][2]=a[i][2];
        pp[i][1]=mm[i][1];
        pp[i][2]=mm[i][2];
    }
    while(x<=p&&y<=q){
        if(a[x][1]>=a[y][1]){
            hp[cntt][1]=a[x][1];
            pp[cntt][1]=mm[x][1];
            hp[cntt][2]=a[x][2];
            pp[cntt][2]=mm[x][2];
            x++;
        }
        else{

            pp[cntt][1]=mm[y][1];
            pp[cntt][2]=mm[y][2];
            hp[cntt][1]=a[y][1];
            hp[cntt][2]=a[y][2];
            y++;
        }
        cntt++;
    }
    if(y<q){
        while(cntt<=r){
            pp[cntt][1]=mm[y][1];
            pp[cntt][2]=mm[y][2];
            hp[cntt][1]=a[y][1];
            hp[cntt][2]=a[y][2];
            y++;
            cntt++;
        }
    }
    if(x<p){
        while(cntt<=r){
            pp[cntt][1]=mm[x][1];
            pp[cntt][2]=mm[x][2];
            hp[cntt][1]=a[x][1];
            hp[cntt][2]=a[x][2];
            x++;
            cntt++;
        }
    }
    for(int j=l;j<=r;j++){
        mm[j][1]=pp[j][1];
        mm[j][2]=pp[j][2];
        a[j][1]=hp[j][1];
        a[j][2]=hp[j][2];

    }
    return;
}
int bl(int k,int ap,int bb,int cc,long long l){
    int p=0;
    if(k<=n){
        bl(k+1,ap+1,bb,cc,l+a[k][1]);
        bl(k+1,ap,bb+1,cc,l+a[k][2]);
        bl(k+1,ap,bb,cc+1,l+a[k][3]);
    }
    if(ap<=n/2&&bb<=n/2&&cc<=n/2){
        ans=max(ans,l);
    }
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(t;t>=1;t--){
        if(n<=16){
            ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        bl(1,0,0,0,0);
        cout<<ans<<endl;
        }
        else{
            ans=0;
            cin>>n;
            stup();
            mgsrt1(1,n);
            aa[1]=0,aa[2]=0,aa[3]=0;
            int k=0;
            while(k<n){
                k++;
                if(aa[mm[k][1]]<n/2){
                    ans+=a[k][1];
                    aa[mm[k][1]]++;
                }
                else if(aa[mm[k][2]]<n/2){
                    ans+=a[k][2];
                    aa[mm[k][2]]++;
                }
                else if(aa[mm[k][3]]<n/2){
                    ans+=a[k][3];
                    aa[mm[k][3]]++;
                }
            }
            cout<<ans<<endl;
            }
    }
    return 0;
}
