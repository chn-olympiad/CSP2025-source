#include <bits/stdc++.h>
using namespace std;
int maxx[10],t,m;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int m=1;m<=t;m++){
        int n,a1,b1,c1,sum,hg[1000][3],ans;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>hg[i][1]>>hg[i][2]>>hg[i][3];
        }
        if(n==2){
            sum=max(hg[1][1]+hg[2][2],hg[1][1]+hg[2][3]);
            sum=max(sum,hg[1][2]+hg[2][1]);
            sum=max(sum,hg[1][2]+hg[2][3]);
            sum=max(sum,hg[1][3]+hg[2][1]);
            sum=max(sum,hg[1][3]+hg[2][3]);
            cout<<sum<<endl;
        }
        else if(n==4){
            sum=max(hg[1][1]+hg[2][1]+hg[3][2]+hg[4][2],max(hg[1][1]+hg[2][1]+hg[3][3]+hg[4][3],max(hg[1][1]+hg[2][1]+hg[3][3]+hg[4][2],max(hg[1][1]+hg[2][1]+hg[3][2]+hg[4][3],max(hg[1][1]+hg[2][2]+hg[3][1]+hg[4][2],max(hg[1][1]+hg[2][2]+hg[3][1]+hg[4][3],max(hg[1][1]+hg[2][2]+hg[3][2]+hg[4][1],max(hg[1][1]+hg[2][2]+hg[3][2]+hg[4][3],max(hg[1][1]+hg[2][2]+hg[3][3]+hg[4][3],max(hg[1][1]+hg[2][2]+hg[3][3]+hg[4][2],hg[1][1]+hg[2][2]+hg[3][3]+hg[4][1]))))))))));
            int cnt=max(hg[1][1]+hg[2][3]+hg[3][1]+hg[4][2],max(hg[1][1]+hg[2][3]+hg[3][1]+hg[4][3],max(hg[1][1]+hg[2][3]+hg[3][2]+hg[4][1],max(hg[1][1]+hg[2][3]+hg[3][2]+hg[4][2],max(hg[1][1]+hg[2][3]+hg[3][2]+hg[4][3],max(hg[1][1]+hg[2][3]+hg[3][3]+hg[4][1],hg[1][1]+hg[2][3]+hg[3][3]+hg[4][2]))))));
            sum=max(sum,cnt);
            sum=max(sum,max(hg[1][2]+hg[2][1]+hg[3][2]+hg[4][1],max(hg[1][2]+hg[2][1]+hg[3][3]+hg[4][3],max(hg[1][2]+hg[2][1]+hg[3][3]+hg[4][2],max(hg[1][2]+hg[2][1]+hg[3][2]+hg[4][3],max(hg[1][2]+hg[2][2]+hg[3][1]+hg[4][1],max(hg[1][2]+hg[2][2]+hg[3][1]+hg[4][3],max(hg[1][2]+hg[2][2]+hg[3][3]+hg[4][1],max(hg[1][2]+hg[2][2]+hg[3][2]+hg[4][3],max(hg[1][2]+hg[2][2]+hg[3][3]+hg[4][3],max(hg[1][2]+hg[2][2]+hg[3][3]+hg[4][1],hg[1][2]+hg[2][2]+hg[3][3]+hg[4][3])))))))))));
            cnt=max(cnt,max(hg[1][2]+hg[2][3]+hg[3][1]+hg[4][2],max(hg[1][2]+hg[2][3]+hg[3][1]+hg[4][3],max(hg[1][2]+hg[2][3]+hg[3][1]+hg[4][1],max(hg[1][2]+hg[2][3]+hg[3][2]+hg[4][1],max(hg[1][2]+hg[2][3]+hg[3][2]+hg[4][3],max(hg[1][2]+hg[2][3]+hg[3][2]+hg[4][3],max(hg[1][2]+hg[2][3]+hg[3][3]+hg[4][1],hg[1][2]+hg[2][3]+hg[3][3]+hg[4][2]))))))));
            sum=max(sum,cnt);
            sum=max(sum,max(hg[1][3]+hg[2][1]+hg[3][2]+hg[4][1],max(hg[1][3]+hg[2][1]+hg[3][3]+hg[4][1],max(hg[1][3]+hg[2][1]+hg[3][3]+hg[4][2],max(hg[1][3]+hg[2][1]+hg[3][3]+hg[4][2],max(hg[1][3]+hg[2][1]+hg[3][3]+hg[4][1],max(hg[1][3]+hg[2][1]+hg[3][2]+hg[4][3],max(hg[1][3]+hg[2][1]+hg[3][2]+hg[4][2],max(hg[1][3]+hg[2][2]+hg[3][1]+hg[4][1],max(hg[1][3]+hg[2][2]+hg[3][1]+hg[4][3],max(hg[1][3]+hg[2][2]+hg[3][1]+hg[4][2],max(hg[1][3]+hg[2][2]+hg[3][2]+hg[4][3],max(hg[1][3]+hg[2][2]+hg[3][2]+hg[4][1],max(hg[1][3]+hg[2][2]+hg[3][3]+hg[4][1],hg[1][3]+hg[2][2]+hg[3][3]+hg[4][2]))))))))))))));
            cnt=max(cnt,max(hg[1][3]+hg[2][3]+hg[3][1]+hg[4][2],max(hg[1][3]+hg[2][3]+hg[3][1]+hg[4][1],max(hg[1][3]+hg[2][3]+hg[3][2]+hg[4][1],hg[1][3]+hg[2][3]+hg[3][2]+hg[4][2]))));
            sum=max(sum,cnt);
            cout<<sum<<endl;
        }
        else{
            sum=max(hg[1][1]+hg[2][1]+hg[3][2]+hg[4][2],max(hg[1][1]+hg[2][1]+hg[3][3]+hg[4][3],max(hg[1][1]+hg[2][1]+hg[3][3]+hg[4][2],max(hg[1][1]+hg[2][1]+hg[3][2]+hg[4][3],max(hg[1][1]+hg[2][2]+hg[3][1]+hg[4][2],max(hg[1][1]+hg[2][2]+hg[3][1]+hg[4][3],max(hg[1][1]+hg[2][2]+hg[3][2]+hg[4][1],max(hg[1][1]+hg[2][2]+hg[3][2]+hg[4][3],max(hg[1][1]+hg[2][2]+hg[3][3]+hg[4][3],max(hg[1][1]+hg[2][2]+hg[3][3]+hg[4][2],hg[1][1]+hg[2][2]+hg[3][3]+hg[4][1]))))))))));
            int cnt=max(hg[1][1]+hg[2][3]+hg[3][1]+hg[4][2],max(hg[1][1]+hg[2][3]+hg[3][1]+hg[4][3],max(hg[1][1]+hg[2][3]+hg[3][2]+hg[4][1],max(hg[1][1]+hg[2][3]+hg[3][2]+hg[4][2],max(hg[1][1]+hg[2][3]+hg[3][2]+hg[4][3],max(hg[1][1]+hg[2][3]+hg[3][3]+hg[4][1],hg[1][1]+hg[2][3]+hg[3][3]+hg[4][2]))))));
            sum=max(sum,cnt);
            sum=max(sum,max(hg[1][2]+hg[2][1]+hg[3][2]+hg[4][1],max(hg[1][2]+hg[2][1]+hg[3][3]+hg[4][3],max(hg[1][2]+hg[2][1]+hg[3][3]+hg[4][2],max(hg[1][2]+hg[2][1]+hg[3][2]+hg[4][3],max(hg[1][2]+hg[2][2]+hg[3][1]+hg[4][1],max(hg[1][2]+hg[2][2]+hg[3][1]+hg[4][3],max(hg[1][2]+hg[2][2]+hg[3][3]+hg[4][1],max(hg[1][2]+hg[2][2]+hg[3][2]+hg[4][3],max(hg[1][2]+hg[2][2]+hg[3][3]+hg[4][3],max(hg[1][2]+hg[2][2]+hg[3][3]+hg[4][1],hg[1][2]+hg[2][2]+hg[3][3]+hg[4][3])))))))))));
            cnt=max(cnt,max(hg[1][2]+hg[2][3]+hg[3][1]+hg[4][2],max(hg[1][2]+hg[2][3]+hg[3][1]+hg[4][3],max(hg[1][2]+hg[2][3]+hg[3][1]+hg[4][1],max(hg[1][2]+hg[2][3]+hg[3][2]+hg[4][1],max(hg[1][2]+hg[2][3]+hg[3][2]+hg[4][3],max(hg[1][2]+hg[2][3]+hg[3][2]+hg[4][3],max(hg[1][2]+hg[2][3]+hg[3][3]+hg[4][1],hg[1][2]+hg[2][3]+hg[3][3]+hg[4][2]))))))));
            sum=max(sum,cnt);
            sum=max(sum,max(hg[1][3]+hg[2][1]+hg[3][2]+hg[4][1],max(hg[1][3]+hg[2][1]+hg[3][3]+hg[4][1],max(hg[1][3]+hg[2][1]+hg[3][3]+hg[4][2],max(hg[1][3]+hg[2][1]+hg[3][3]+hg[4][2],max(hg[1][3]+hg[2][1]+hg[3][3]+hg[4][1],max(hg[1][3]+hg[2][1]+hg[3][2]+hg[4][3],max(hg[1][3]+hg[2][1]+hg[3][2]+hg[4][2],max(hg[1][3]+hg[2][2]+hg[3][1]+hg[4][1],max(hg[1][3]+hg[2][2]+hg[3][1]+hg[4][3],max(hg[1][3]+hg[2][2]+hg[3][1]+hg[4][2],max(hg[1][3]+hg[2][2]+hg[3][2]+hg[4][3],max(hg[1][3]+hg[2][2]+hg[3][2]+hg[4][1],max(hg[1][3]+hg[2][2]+hg[3][3]+hg[4][1],hg[1][3]+hg[2][2]+hg[3][3]+hg[4][2]))))))))))))));
            cnt=max(cnt,max(hg[1][3]+hg[2][3]+hg[3][1]+hg[4][2],max(hg[1][3]+hg[2][3]+hg[3][1]+hg[4][1],max(hg[1][3]+hg[2][3]+hg[3][2]+hg[4][1],hg[1][3]+hg[2][3]+hg[3][2]+hg[4][2]))));
            sum=max(sum,cnt);
            cout<<sum*n*n<<endl;
        }

    }
    return 0;
}
