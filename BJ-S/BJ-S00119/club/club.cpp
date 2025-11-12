#include<bits/stdc++.h>
#define ll long long
struct node{
    ll a,b,c;
}arr[1000010],brr[1000010],crr[1000010];
bool cmp1(node A,node B){
    if(A.a>B.a){
        return A.a<B.a;
    }
}
bool cmp2(node A,node B){
    if(A.b>B.b){
        return A.b<B.b;
    }
}
bool cmp3(node A,node B){
    if(A.c>B.c){
        return A.c<B.c;
    }
}
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t,n,x=0,y=0,z=0,sum=0,m=0,g=0,h=0;
    cin>>t;
    for(ll k=1;k<=t;k++){
    cin>>n;
    for(ll i=1;i<=n;i++){
    cin>>arr[i].a>>arr[i].b>>arr[i].c;
    if(max(arr[i].a,max(arr[i].b,arr[i].c))==arr[i].a){
    x++;
    sum+=arr[i].a;
    crr[++m].a=arr[i].a-max(arr[i].b,arr[i].c);
    }else if(max(arr[i].a,max(arr[i].b,arr[i].c))==arr[i].b){
    y++;
    sum+=arr[i].b;
    crr[++g].b=arr[i].b-max(arr[i].a,arr[i].c);
    }else{
    z++;
    sum+=arr[i].c;
    crr[++h].c=arr[i].c-max(arr[i].b,arr[i].a);
    }
    }
    if(x>n/2){
    sort(crr+1,crr+m+1,cmp1);
    for(ll q=1;q<=x-n/2;q++){
    sum-=crr[q].a;
    }
    }else if(y>n/2){
    sort(crr+1,crr+g+1,cmp2);
    for(ll q=1;q<=y-n/2;q++){
    sum-=crr[q].b;
    }
    }else if(z>n/2){
    sort(crr+1,crr+h+1,cmp3);
    for(ll q=1;q<=z-n/2;q++){
    sum-=crr[q].c;
    }
    }
    cout<<sum<<endl;
    sum=0;
    x=0;
    y=0;
    z=0;
    m=0;
    g=0;
    h=0;
    }
    return 0;
}
