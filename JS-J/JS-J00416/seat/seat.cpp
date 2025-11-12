#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int sum=n*m,score,rank;
    for(int i=1;i<=sum;i++){
        cin>>a[i];
        if(i==1) score=a[i];
    }
    sort(a+1,a+sum+1,cmp);
    for(int i=1;i<=sum;i++){
        if(a[i]==score) {
            rank=i;
            break;
        }
    }
    //cout<<rank<<"\n";
    int lie=rank/n+1,flag=0;
    if(rank%n==0){
        lie-=1;
        flag=1;
    } 
    int hang;
    if(lie%2==1){
        if(flag){
            hang=n;
        }else{
            hang=rank%n;
        }
    }
    else if(lie%2==0){
        if(flag){
            hang=1;
        }else{
            hang=n-(rank%n)+1;
        }
    }
    cout<<lie<<' '<<hang;
    return 0;
}