#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct node{
    long long score;
    long long cn;
    long long rn;
}a[120];
bool cmp(node x,node y){
    return x.score>y.score;
}//hello world
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    long long num=n*m;
    for(int i=1;i<=num;i++){
        cin>>a[i].score;
    }
    if(n==1&&m==1){
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    long long num1=a[1].score;
    sort(a+1,a+num+1,cmp);
    for(int i=1;i<=num;i++){
        a[i].cn=0;
        a[i].rn=0;
    }
    long long hang=1,lie=1;
    a[1].cn=1;
    a[1].rn=1;
    lie=1;
    hang=2;
    for(int i=2;i<=num;i++){
        if(a[i].cn==0&&a[i].rn==0){
            a[i].cn=lie;
            a[i].rn=hang;
        }
        if(hang==n){
            lie+=1;
            a[i+1].cn=lie;
            a[i+1].rn=hang;
            a[i+2].cn=lie;
            a[i+2].rn=hang-1;
            hang--;
        }
        if(hang==1&&lie!=1){
            lie+=1;
            a[i+1].cn=lie;
            a[i+1].rn=hang;
            a[i+2].cn=lie;
            a[i+2].rn=hang+1;
            hang++;
        }
        if(a[i].cn==0&&a[i].rn==0){
            hang++;
        }
    }
    for(int i=1;i<=num;i++){
        if(a[i].score==num1){
            cout<<a[i].cn<<" "<<a[i].rn<<endl;
        }
    }
    return 0;
}
