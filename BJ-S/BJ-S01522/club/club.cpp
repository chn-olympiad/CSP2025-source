#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
int t,n,a[N][4],p[4],h,x,fa,l;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int ioo=1;ioo<=t;ioo++){
        cin>>n;
        x=n%2;
        fa=-1;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                cin>>a[j][k];
            }
        }

            for(int i=1;i<=3;i++)p[i]=0;
            h=0;
            for(int i=1;i<=n;i++){
                if((max(a[i][1],a[i][2])==a[i][1]&&max(a[i][1],a[i][3])==a[i][1])&&p[1]+1<=x){
                    p[1]+=1,h+=a[i][1];
                }
                if((max(a[i][1],a[i][2])==a[i][2]&&max(a[i][2],a[i][3])==a[i][2])&&p[2]+1<=x){
                    p[2]+=1,h+=a[i][2];
                }
                if((max(a[i][1],a[i][3])==a[i][3]&&max(a[i][2],a[i][3])==a[i][3])&&p[3]+1<=x){
                    p[3]+=1,h+=a[i][3];
                }
            }

        cout<<h;
    }
    return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/

