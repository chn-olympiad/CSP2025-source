#include<bits/stdc++.h>
using namespace std;
struct stu{
    int num;
    int sum;
    int a,b;
}s[110];
bool cmp(stu x,stu y){
    return x.sum>y.sum;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int key;
    cin>>key;
    s[1].sum=key;
    for(int i=2;i<=n*m;i++)
        cin>>s[i].sum;
    sort(s+1,s+n*m+1,cmp);
    int cc=1,cr=1;
    bool flag=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[(i-1)*m+j].sum==key)
                cout<<cr<<' '<<cc;
            if(flag)
                cc++;
            else
                cc--;
            if(cc>n){
                cr++;
                cc--;
                flag=false;
            }
            if(cc<1){
                cr++;
                cc++;
                flag=true;
            }
        }
    }

    return 0;
}
