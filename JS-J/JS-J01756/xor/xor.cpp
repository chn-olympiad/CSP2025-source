#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int c1;
int cnt1;
int cnt0;
int cnt;
int s;
int t1[N];
int t2[N];
int t3[N];
int t(int l,int p){
    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));
    memset(t3,0,sizeof(t3));
    int tt1=1;
    int tt2=1;
    while(l!=0){
        t1[tt1]=l%10;
        l/=10;
        tt1++;
    }
    while(p!=0){
        t2[tt2]=p%2;
        p/=2;
        tt2++;
    }
    for(int i=1;i<=max(tt2,tt1);i++){   
        if(t1[i]==t2[i]){
            t3[i]=0;
        }else{
            t3[i]=1;
        }
    }
    int h=0;
    int o=1;
    for(int i=1;i<=max(tt2,tt1);i++){
        h=h+o*a[i];
        o*=2;
    }
    return h;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    //cout<<t(0,2)<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                c1++;
            }
        }
        cout<<c1/2<<endl;
        return 0;
    }else{
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    cnt1++;
                }
            }
            cout<<cnt1<<endl;
            return 0;
        }else{
            for(int i=1;i<=n;i++){
                s=t(s,a[i]);
                if(s==k){
                    cnt++;
                    //cout<<a[i]<<endl;
                    s=0;
                }
            }
            cout<<cnt<<endl;
            return 0;
        }

    }
    return 0;
}