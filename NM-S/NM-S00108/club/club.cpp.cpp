#include<bits/stdc++.h>
using namespace std;
int t,n,zl,yl;
long long s1,s2,s3;
struct S{
    int x,y,z;
    int f1,f2,f3;
}a[10005];
int cmp(S x,S y){
    return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            a[i].f1=a[i].f2=a[i].f3=1;
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].z==0){
                zl++;
                a[i].f3=0;
            }
            if(a[i].y==0){
                yl++;
                a[i].f2=0;
            }
            s1+=a[i].x;
            s2+=a[i].y;
            s3+=a[i].z;
        }
        if(zl==n&&yl==n){
        	int o;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                o+=a[i].x;
            }
            cout<<o<<endl;
            break;
        }

    }
    return 0;
}
