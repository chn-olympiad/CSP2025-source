#include<bits/stdc++.h>
using namespace std;
int t,n,sum1,sum2,l1,l2,visa[100001],visb[100001],visc[100001],l3,ans;
struct club{
    int x,y,z,id;
}a[100001];
int cmp1(int n,int m){
    return a[n].x>a[m].x;
}
int cmp2(int n,int m){
    return a[n].y>a[m].y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                //sum1+=a[i].x;
            visa[++l1]=i;
        }else if(a[i].x<=a[i].y&&a[i].y>=a[i].z){
            //sum2+=a[i].y;
            visb[++l2]=i;
        }else{
            visc[++l3]=i;
        }
        }sort(visa+1,visa+l1+1,cmp1);
        while(l1>n/2){
            if(a[visa[l1]].y>a[visa[l1]].z){
                visb[++l2]=visa[l1--];
            }else{
                visc[++l3]=visa[l1--];
            }
        }sort(visb+1,visb+1+l2,cmp2);
        while(l2>n/2){
                visc[++l3]=visb[l2--];
        }for(int i=1;i<=l1;i++){
            ans+=a[visa[i]].x;
        }for(int i=1;i<=l2;i++){
            ans+=a[visb[i]].y;
        }for(int i=1;i<=l3;i++){
            ans+=a[visc[i]].z;
        }cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
