#include<bits/stdc++.h>
using namespace std;
int n,m;
int a1,a;
int st;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1;
    if(n*m==1){
        cout<<"1 1"<<endl;
        return 0;
    }
    for(int i=1;i<n*m;i++){
        cin>>a;
        if(a>a1)st++;
    }
    int st1=st+1;
    int ann=(st/n)+1;
    int anm=0;

    if(ann%2==0){
        anm=n-(st1%n)+1;
        if(st1%n==0)anm=1;
    }else{
        anm=st1%n;
        if(st1%n==0)anm=n;
    }
    cout<<ann<<" "<<anm<<endl;
    return 0;
}
