#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z,f=1;
}a[1000005];
int check(int p,int n,int s){
    int b[4]={0},q=0,i=0;
    while(i<=n){
        if(a[++q].f==0) continue;
        if(b[a[q].z]<n/2){
            s+=a[q].x;
            i++;
           b[a[q].z]++;
            for(int j=i;j<=p;j++){
                if(a[q].y==a[j].y) a[j].f=0;
            }
        }
    }
    return s;
}
int cmp(node x,node y){
   return x.x>y.x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,x,y,z,p=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[++p].x;
                a[p].y=i;
                a[p].z=j;
                a[p].f=1;
            }
        }
        sort(a+1,a+p+1,cmp);
        cout<<check(p,n,0)<<endl;
    }
    return 0;
}
