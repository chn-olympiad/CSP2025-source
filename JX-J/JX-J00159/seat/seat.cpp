#include<bits/stdc++.h>
using namespace std;
string a;
int n[10000],h[1000][1000];
int b,c,d,e=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>b>>c>>d;
    n[0]=d;
    for(int i=1;i<b*c;i++){
        cin>>n[i];
    }
    sort(n,n+b*c,cmp);

    for(int i=0;i<b*c;i++){
        if(n[i]==d){
            cout<<i/c+1<<' ';
            if((i+1)%b==0&&e==0){
                cout<<b<<' ';
            }else if((i+1)%b==0&&e==1){
                cout<<1;
            }else if(e==1){
                cout<<b-(i+1)%b<<' ';
            }
            else if(e==0){
                cout<<(i+1)%b+1<<' ';
            }

            return 0;
            //cout<<n[i];
        }
        if(e==0){
            e=1;
        }else if(e==1){
            e=0;
        }
    }
    return 0;
}
