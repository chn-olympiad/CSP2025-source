#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;
int n,k,ab[100001];
bool a[5001][21];
bool tp[21],pf[3]={true,true,true};
bool xorn(bool a,bool b){
    if(a==b){
        return false;
    }
    else{
        return true;
    }
}
int wo(int l,int r){
    int toto=0,ans;
    for(int i=l;i<=r;i++){
        int tp=i,tot=1;
        while(tp>=1){
            a[1][tot]=tp%2;
            tp/=2;
            tot++;
        }
        toto++;
    }
    int ansn[21];
    for(int i=1;i<=20;i++){
        ansn[i]=a[1][i];
    }
    for(int i=1;i<=toto;i++){
        for(int i=1;i<=20;i++){
            ansn[i]=xorn(ansn[i],a[r][i]);
        }
    }
    for(int i=1;i<=20;i++){
        int pown=pow(2,i);
        ans=ansn[i]*pown;
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        memset(tp,false,sizeof(tp));
        cin>>ab[i];
        if(n==1&&ab[i]==k){
            cout<<"1";
            return 0;
        }
        if(n==1&&ab[i]!=k){
            cout<<"0";
            return 0;
        }
        if(ab[i]!=1){
            pf[1]=false;
        }
        if(!pf[1]&&ab!=0){
            pf[2]=false;
        }
    }
    if(pf[1]&&n==2){
        cout<<"1"<<endl;
    }
    if(pf[1]&&n!=2){//
        cout<<floor(n/2.0);
    }
    return 0;
}
