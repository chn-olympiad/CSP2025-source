#include<bits/stdc++.h>
using namespace std;
struct stu{
    int s,id;
    int flag=0;
};
bool cmp(stu a,stu b){
    return a.s>b.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    stu a[100001];
    long long ans;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].s;
        a[i].id=i;
        if(i==1)a[i].flag=1;
    }
    sort(a+1,a+1+n*m,cmp);
     int id2=0;
   for(int i=1;i<=n*m;i++){
    if(a[i].flag==1){
        id2=i;
        break;
    }
   }
   //cout<<id2;
   int l=(id2+n-1)/n;
   int h;
   if(l%2==1){
     h=id2-(l-1)*n;
   }
   else{
     h=n-id2+(l-1)*n+1;
   }
   cout<<l<<" "<<h;
    return 0;
}

/*4 4
87  66
86 70 53
82 73 52
81 77 44
*/
