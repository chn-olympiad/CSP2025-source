#include<bits/stdc++.h>
using namespace std;
struct node{
long long num,id;
}a[110];
bool cmp(node a, node b){
return a.num>b.num;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i].num;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    long long cnt=0;
    for(long long i=1;i<=n*m;i++) if(a[i].id==1) cnt=i;
    long long num=0;
    if(cnt%n==0) num=cnt/n;
    else num=cnt/n+1;
    long long s=cnt%n;
    if(s==0) s=n;
    if(num%2==1){
        cout<<num<<" "<<s;
    }
    else cout<<num<<" "<<n-s+1;
    fclose(stdin);
    fclose(stdout);
return 0;
}
