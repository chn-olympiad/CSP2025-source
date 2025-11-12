#include <bits/stdc++.h>
using namespace std;
int n,r1=0,r2=0,r3=0;
int main(){
    freopen("club.in","r","stdin");
    freopen("club.out","w","stdout");
    int t,ans1=0,ans2=0,ans3=0;
    cin>>t;
    while(t--){
        cin>>n;
        int hg[n][5];
    for(int i=1;i<=n;i++){
        cin>>hg[i][1]>>hg[i][2]>>hg[i][3];
        if(hg[i][1]>=hg[i][2]&&hg[i][1]>=hg[i][3]){
            if(r1<n/2){
                r1++;
                ans1=ans1+hg[i][1];
            }
        }
        else if(hg[i][2]>=hg[i][1]&&hg[i][2]>=hg[i][3]){
            if(r2<n/2){
                r2++;
                ans2=ans2+hg[i][2];
            }
        }
         else if(hg[i][3]>=hg[i][2]&&hg[i][3]>=hg[i][1]){
            if(r3<n/2){
                r3++;
                ans3=ans3+hg[i][3];
            }
        }

    }

cout<<(ans1+ans2+ans3);
    }
return 0;
}
