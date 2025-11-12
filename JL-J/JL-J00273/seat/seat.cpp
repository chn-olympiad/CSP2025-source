#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m],s[n][m],f=0,fid=0;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(i==0){
            f=a[i];
        }
    }
    sort(a,a+n*m+1,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==f){
            fid=i+1;
            break;
        }
    }
    int fn,fm;
    fn=fid/n;
    if(fid%n!=0){
        fn+=1;
        if(fn%2==0){
            fm=n+1-(fid-n*(fn-1));
            cout<<fn<<" "<<fm<<endl;
        }
        else{
            fm=fid-n*(fn-1);
            cout<<fn<<" "<<fm<<endl;
            return 0;
        }
    }
    else{
        if(fn%2==0){
            cout<<fn<<" "<<"1"<<endl;
        }
        else{
            cout<<fn<<" "<<n<<endl;
        }
    }
    return 0;
}
