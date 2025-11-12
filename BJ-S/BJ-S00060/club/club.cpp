#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int x,y,z;
};
bool cmp(node A,node C){
    return max(A.x,A.y)>max(C.x,C.y);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        node a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        int b1,b2,ans=0;
        b1=b2=n/2;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].x>a[i].y){
                if(b1>0){
                    ans+=a[i].x;
                    b1--;
                }else{
                    ans+=a[i].y;
                    b2--;
                }
            }else{
                if(b2>0){
                    ans+=a[i].y;
                    b2--;
                }else{
                    ans+=a[i].x;
                    b1--;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
