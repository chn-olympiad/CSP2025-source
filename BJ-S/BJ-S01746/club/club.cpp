#include<bits/stdc++.h>
using namespace std;
int a[100000][3];
int dis[100000][3];
int main(){
    int t;
    space('in',"club.in");
    space('out',"club.out");
    cin>>t;
    for(int z=1;z<=t;z++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1];
            cin>>a[i][2];
            cin>>a[i][3];
        }
        for(int i=1;i<=n;i++){
            bis[i][1]=a[i][1]+max(bis[i-1][1],max(bis[i-1][2],bis[i-1][3]));
            bis[i][2]=a[i][2]+max(bis[i-1][1],max(bis[i-1][2],bis[i-1][3]));
            bis[i][3]=a[i][3]+max(bis[i-1][1],max(bis[i-1][2],bis[i-1][3]));
        }
        int s=max(bis[i-1][1],max(bis[i-1][2],bis[i-1][3]));
        printf("%b",s);
        cout<<endl;
    }
    return 0;
}