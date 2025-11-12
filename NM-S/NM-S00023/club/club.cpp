#include<bits/stdc++.h>
using namespace std;
int t,n,a[100002][3],cnt,b,c;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int k=0;k<t;k++){
        cin>>n;
        cnt=0;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(int i=0;i<n/2;i++){
            b=a[0][0];
            c=0;
            for(int i=0;i<n;i++){
                if(a[i][0]>b){
                    b=a[i][0];
                    c=i;
                }
            }
            cnt+=b;
            a[c][0]=0;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
