#include<bits/stdc++.h>
using namespace std;
int f1[4][3]={0,1,0,0,1,0,0,2,0,0,2,0};
int n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int a[n][3];
        for(int j=0;j<n;j++){
            cin>>a[j][0]>>a[j][1]>>a[j][2];
        }

        int cnt=0;
        for(int j=0;j<n;j++){
          int m=max(a[j][1],max(a[j][0],a[j][2]));
          cnt+=m;
        }
        cout<<cnt<<endl;
    }
return 0;}
