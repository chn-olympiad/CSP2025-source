#include<bits/stdc++.h>
using namespace std;
struct node{
    int m1,m2,m3,m4;
}a[10005];
bool cmp(node x,node y){
    return x.m1>y.m1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,sum1=0,sum2=0,sum3=0,sum;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j].m1>>a[j].m2>>a[j].m3;
            if(max(max(a[j].m1,a[j].m2),a[j].m3)==a[j].m1){
                a[j].m4=1;
                sum1++;
            }else if(max(max(a[j].m1,a[j].m2),a[j].m3)==a[j].m2){
                a[j].m4=2;
                sum2++;
            }else{
                a[j].m4=3;
                sum3++;
            }
        }
        cout<<sum2<<endl;
    }
    return 0
}
