#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);//.out!!!

    int n,m;//n hang m lie
    cin>>n>>m;
    for(int i=0;i<n*m;++i){
        cin>>a[i];
    }
    int ming=a[0], posm;
    sort(a,a+n*m,cmp);
    /*for(int i=0;i<n*m;++i){
        cout<<a[i]<<' ';
    }
    cout<<endl;*/
    for(int i=0;i<n*m;++i){
        if(a[i]==ming)posm=i;
    }
    if((posm/n)%2==0){
        cout<<(posm/n)+1<<' '<<(posm%n)+1;//nhang mlie
    }else{
        cout<<(posm/n)+1<<' '<<n-(posm%n);
    }
    return 0;
    /*
2 2
99 100 97 98

2 2
98 99 100 97
    */
}
