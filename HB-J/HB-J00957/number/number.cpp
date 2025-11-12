#include<bits/stdc++.h>
using namespace std;
int b[1100000];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int l=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9') b[++l]=a[i]-'0';
    }

    sort(b+1,b+l+1,cmp);
    bool f=0;
    int p=1;
    for(int i=1;i<=l;i++){
        if(b[i]!=0){
            f=1;p=i;break;

        }
    }
//    cout<<p<<" "<<f<<endl;
//    for(int i=1;i<=l;i++){
//            cout<<b[i]<<" ";
//    }cout<<endl;
    if(f==0) cout<<0;
    else {
        for(int i=p;i<=l;i++){
            cout<<b[i];
        }
    }
    return 0;
}
