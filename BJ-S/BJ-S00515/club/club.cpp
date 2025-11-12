#include <iostream>
#include <fstream>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long am[n+5][4],bm[n+5][4];

        long long a=0,b=0,c=0,nn=n/2;
        for(int i=1;i<=n;i++){
            cin>>am[i][1]>>am[i][2]>>am[i][3];
        }
        if(n==2){
            long long qq=max(am[2][2],am[2][3])+am[1][1],ww=max(am[2][1],am[2][3])+am[1][2],ee=max(am[2][1],am[2][3])+am[1][3];
            long long gg=max(ee,max(qq,ww));
            cout<<gg<<endl;
            continue;
        }
        bm[1][1]=am[1][1];
        bm[1][2]=am[1][2];
        bm[1][3]=am[1][3];
        if(am[1][1]==max(am[1][1],max(am[1][2],am[1][3])))a++;
        if(am[1][2]==max(am[1][1],max(am[1][2],am[1][3])))b++;
        if(am[1][3]==max(am[1][1],max(am[1][2],am[1][3])))c++;
        for(int i=2;i<=n;i++){
            long long x=0,y=0,z=0;
            a>=nn?x=0:x=am[i][1];
            b>=nn?y=0:y=am[i][2];
            c>=nn?z=0:z=am[i][3];
            bm[i][1]=a>=nn?max(x,max(y,z)):max(   bm[i-1][3]+max(x,max(y,z)),max(   bm[i-1][1]+max(x,max(y,z)),   bm[i-1][2]+max(x,max(y,z)))   );
            bm[i][2]=b>=nn?max(x,max(y,z)):max(   bm[i-1][3]+max(x,max(y,z)),max(   bm[i-1][1]+max(x,max(y,z)),   bm[i-1][2]+max(x,max(y,z)))   );
            bm[i][3]=c>=nn?max(x,max(y,z)):max(   bm[i-1][3]+max(x,max(y,z)),max(   bm[i-1][1]+max(x,max(y,z)),   bm[i-1][2]+max(x,max(y,z)))   );
            if(x==max(x,max(y,z)))a++;
            if(y==max(x,max(y,z)))b++;
            if(z==max(x,max(y,z)))c++;
        }
        cout<<max(bm[n][1],max(bm[n][2],bm[n][3]))<<endl;
    }
    return 0;
}