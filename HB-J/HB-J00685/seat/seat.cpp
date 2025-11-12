#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct stu{
    int val;
    bool tof;
}a[105];
int n,m;
bool cmp(stu a,stu b){
    return a.val>b.val;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i].val;
        a[i].tof=false;
    }
    a[1].tof=true;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;++i){
        if(a[i].tof==true){
            int num=i/n;
            if(i%n!=0){
                ++num;
            }
            int num1=i%n;
            if(num1==0)num1=n;
            if(num%2==0){
                cout<<num<<' '<<n-num1+1;
            }else{
                cout<<num<<' '<<num1;
            }
            break;
        }
    }
    return 0;
}