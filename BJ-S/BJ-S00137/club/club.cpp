#include <bits/stdc++.h>
using namespace std;
int l[100100][3],n;
int m=0;
int save(int t,int num){
    if(t>=n){return num;}
    m=max(save(t+1,num+l[t][1]),m);
    m=max(save(t+1,num+l[t][2]),m);
    m=max(save(t+1,num+l[t][0]),m);
    return m;
}
int main(){
    //continue;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,i=0;
    cin>>t;
    while(i<t){
        int j=0;
        cin>>n;
        while(j<n){
            cin>>l[j][0]>>l[j][1]>>l[j][2];
            j++;
        }
        m=0;
        cout<<save(0,0)<<"\n";
        i++;
    }
    return 0;
}
