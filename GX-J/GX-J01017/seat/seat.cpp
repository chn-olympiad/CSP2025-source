#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,ID;
struct Code{
    int p,id;
};

bool cmp(Code a,Code b){
    return a.p>b.p;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    Code a[n*m+3]={0};
    for(int i=1;i<=n*m;i++){
        cin>>a[i].p;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1)ID=i;
    }
    int tmp=ID%n;
    c=ID/n;
    if(tmp!=0){
        c++;
    }
    if(c%2==0){
        if(tmp==0){
            r=1;
        }else{
            r=n-tmp+1;
        }
    }else{
        if(tmp==0){
            r=n;
        }else{
            r=tmp;
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
