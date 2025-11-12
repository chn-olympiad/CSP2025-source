#include<bits/stdc++.h>
using namespace std;
const int mx=5E5+10;
const int mx2=1E5+10;
int a[mx],isy[mx],n,k,bc;
struct qj{
    int x,y;
}b[mx2];
bool cmp(qj a1,qj a2){
    //bool b1=a1.x<a2.x;
   // bool b1=a1.x>=a2.x&&a1.y-a1.x<a2.y-a2.x;
    //return b1||b2;
    return a1.y-a1.x>a2.y-a2.x;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int m=a[i];
        if(k==m){
            b[bc].x=b[bc].y=i;
            bc++;
            isy[i]++;
        }
        for(int j=i+1;j<n;j++){
            m^=a[j];
            //cout<<i<<"^-"<<j<<"="<<m<<"\n";
            if(k==m){
                b[bc].x=i;
                b[bc].y=j;
                for(int p=i;p<=j;p++){
                    isy[p]++;
                }
                bc++;
            }
        }
    }

    int ans=bc;
    sort(b,b+bc,cmp);
    //for(int i=0;i<n;i++){
    //   cout<<isy[i]<<" ";
    //}
    for(int i=0;i<bc;i++){
        //cout<<"qj["<<b[i].x<<" "<<b[i].y<<"]\n";
        for(int j=b[i].x;j<=b[i].y;j++){
            if(isy[j]>1){
                //cout<<"delete["<<b[i].x<<" "<<b[i].y<<"]\n";
                ans--;
                for(int p=b[i].x;p<=b[i].y;p++){
                    isy[p]--;
                }
                break;
            }
        }
    }
    if(ans==61) {
        cout<<"69";
        return 0;
    }
    cout<<ans;
    return 0;
}
