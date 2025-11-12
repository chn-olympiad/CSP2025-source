#include<bits/stdc++.h>
using namespace std;
int n,m,x;
struct student{
    int id;
    int code;
}a[105];
bool cmp(student u,student v) {return u.code>v.code;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++){
        cin>>a[i].code;
        a[i].id=i;
    }
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=(n*m);i++)
        if(a[i].id==1){
            x=i;
            break;
        }
    int c=1,r=1,sum=1;
    bool f=1;
    while(true){
        if(sum==x) break;
        if(f==1) r++,sum++;
        else if(f==0) r--,sum++;
        if(r>n){
            r--;
            c++;
            f=0;
        }
        if(r<1){
            r++;
            c++;
            f=1;
        }

    }
    cout<<c<<" "<<r;
    return 0;
}
