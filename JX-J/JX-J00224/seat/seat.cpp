#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[10][10];
bool cmp(int l,int r){
    return l>r;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int score=a[1];
    sort(a+1,a+n*m+1,cmp);
    int tmp;
    for(int i=1;i<=n*m;i++){
        if(a[i]==score){
            tmp=i;
            break;
        }
    }
    int c=ceil(1.0*tmp/m);
    cout<<c<<' ';
    if(c%2==1){
        if(tmp%m==0){
            cout<<m<<endl;
            return 0;
        }
        cout<<tmp%m<<endl;
    }
    else cout<<m-tmp%m+1<<endl;
    return 0;
}

