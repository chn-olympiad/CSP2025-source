#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1,cmp);
    int c=1,r=1,cnt=1;
    while(a[cnt]!=x){
        if(c%2==1){
            if(r==1){
                r++;
            }else if(r==n){
                c++;
            }else{
                r++;
            }
        }else{
            if(r==1){
                c++;
            }else if(r==n){
                r--;
            }else{
                r--;
            }
        }
        cnt++;
    }
    cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
