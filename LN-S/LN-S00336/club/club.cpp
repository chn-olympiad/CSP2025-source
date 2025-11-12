#include<bits/stdc++.h>
using namespace std;
long long sum,b[5],n;
struct s{
    long long x,y,z,j,maxx,maxi;
}a[100005];
bool cmp(s o,s p){
    if(o.maxx>p.maxx){
        if(b[o.maxi]>=n/2){

            if(o.x==o.maxx)o.maxx=max(o.y,o.z);
            else if(o.y==o.maxx)o.maxx=max(o.z,o.x);
            else if(o.z==o.maxx)o.maxx=max(o.x,o.y);
        }
    }
    if(p.maxx>o.maxx){
        if(b[p.maxi]>=n/2){

            if(p.x==p.maxx)p.maxx=max(p.y,p.z);
            else if(p.y==p.maxx)p.maxx=max(p.z,p.x);
            else if(p.z==p.maxx)p.maxx=max(p.x,p.y);
        }
    }
    if(max(o.maxx,p.maxx)==max(o.x,p.x))b[1]--;
    else if(max(o.maxx,p.maxx)==max(o.y,p.y))b[2]--;
    else b[3]--;
    return o.maxx>p.maxx;
}
bool cmpx(s o,s p){
    return o.x>p.x;
}
bool cmpy(s o,s p){
    return o.y>p.y;
}
bool cmpz(s o,s p){
    return o.z>p.z;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        sum=0;
        cin>>n;
        for(long long i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>a[i].y&&a[i].x>a[i].z)a[i].maxx=a[i].x,a[i].maxi=1,b[1]++;
            else if(a[i].y>a[i].x&&a[i].y>a[i].z)a[i].maxx=a[i].y,a[i].maxi=2,b[2]++;
            else if(a[i].z>a[i].x&&a[i].z>a[i].y)a[i].maxx=a[i].z,a[i].maxi=3,b[3]++;

        }
        sort(a+1,a+n+1,cmp);
        for(long long i=1;i<=n;i++){

            sum+=a[i].maxx;

        }
        cout<<sum<<endl;
    }
    return 0;
}
