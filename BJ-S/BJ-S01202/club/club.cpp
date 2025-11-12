#include <bits/stdc++.h>
using namespace std;
int t,n;
struct student{
    int d[3];
    int fav;
}a[100005];
bool cmp(student x,student y){
    if(x.fav==y.fav){
        return x.d[x.fav-1]>y.d[y.fav-1];
    }
    return x.fav<y.fav;
}
int as;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].d[0]>>a[i].d[1]>>a[i].d[2];
            if(max(a[i].d[0],max(a[i].d[1],a[i].d[2]))==a[i].d[0]){
                a[i].fav=1;
            }
            else if(max(a[i].d[0],max(a[i].d[1],a[i].d[2]))==a[i].d[1]){
                a[i].fav=2;
            }
            else{
                a[i].fav=3;
            }
        }
        sort(a+1,a+n+1,cmp);
        int i;
        for(i=1;i<=n/2;i++){
            if(a[i].fav!=1){
                break;
            }
            else{
                as+=a[i].d[0];
            }
        }
        int j=i;
        for(;i<=j-1+n/2;i++){
            if(a[i].fav!=2){
                break;
            }
            else{
                as+=a[i].d[2];
            }
        }
        j=i;
        for(;i<=n;i++){
            if(a[i].fav!=3){
                break;
            }
            else{
                as+=a[i].d[2];
            }
        }
        cout<<as;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
