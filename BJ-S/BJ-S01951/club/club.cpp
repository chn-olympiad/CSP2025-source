#include<bits/stdc++.h>
using namespace std;
int n,maxx=0;
int t,a[100005][3],a1[100005],a2,a3;
int into(int w,int c1,int c2,int c3,int z1,int z2,int z3){
    int sign;
    if(w==n){
        if(maxx<c1+c2+c3)maxx=c1+c2+c3;
        return 0;
    }
    if(z1<n/2){
        c1+=a[w][0];
        z1++;
        sign=0;
    }
    else if(z2<n/2){
        c2+=a[w][1];
        z2++;
        sign=1;
    }
    else{
        c3+=a[w][2];
        z3++;
        sign=2;
    }
    into(w+1,c1,c2,c3,z1,z2,z3);
    if(sign==0){
        c1-=a[w][0];
        z1--;
    }
    else if(sign==1){
        c2-=a[w][1];
        z2--;
    }
    else{
        c3-=a[w][2];
        z3--;
    }
    if(z2<n/2){
        c2+=a[w][1];
        z2++;
        sign=1;
    }
    else if(z3<n/2){
        c3+=a[w][2];
        z3++;
        sign=2;
    }
    else{
        c1+=a[w][0];
        z1++;
        sign=0;
    }
    into(w+1,c1,c2,c3,z1,z2,z3);
    if(sign==0){
        c1-=a[w][0];
        z1--;
    }
    else if(sign==1){
        c2-=a[w][1];
        z2--;
    }
    else{
        c3-=a[w][2];
        z3--;
    }
    if(z3<n/2){
        c3+=a[w][2];
        z3++;
        sign=2;
    }
    else if(z1<n/2){
        c1+=a[w][0];
        z1++;
        sign=0;
    }
    else{
        c2+=a[w][1];
        z2++;
        sign=1;
    }
    into(w+1,c1,c2,c3,z1,z2,z3);
    if(sign==0){
        c1-=a[w][0];
        z1--;
    }
    else if(sign==1){
        c2-=a[w][1];
        z2--;
    }
    else{
        c3-=a[w][2];
        z3--;
    }
    return 0;
}
int into2(int w,int c1,int c2,int z1,int z2){
    int sign;
    if(w==n){
        if(maxx<c1+c2)maxx=c1+c2;
        return 0;
    }
    if(z1<n/2){
        c1+=a[w][0];
        z1++;
        sign=0;
    }
    else if(z2<n/2){
        c2+=a[w][1];
        z2++;
        sign=1;
    }
    into2(w+1,c1,c2,z1,z2);
    if(sign==0){
        c1-=a[w][0];
        z1--;
    }
    else {
        c2-=a[w][1];
        z2--;
    }
    if(z2<n/2){
        c2+=a[w][1];
        z2++;
        sign=1;
    }
    else if(z1<n/2){
        c1+=a[w][0];
        z1++;
        sign=0;
    }
    into2(w+1,c1,c2,z1,z2);
    if(sign==0){
        c1-=a[w][0];
        z1--;
    }
    else{
        c2-=a[w][1];
        z2--;
    }
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        if(n<=200){
            for(int j=0;j<n;j++){
                cin>>a[j][0]>>a[j][1]>>a[j][2];

            }
            if(n<=30)into(0,0,0,0,0,0,0);
            else if(n==200)into2(0,0,0,0,0);
        }
        else{
            for(int j=0;j<n;j++){
                cin>>a1[j]>>a2>>a3;
            }
            sort(a1,a1+n);
            for(int i=n-1;i>=n/2;i--){
                maxx+=a1[i];
            }
        }
        cout<<maxx<<endl;
        maxx=0;
    }
    return 0;
}
