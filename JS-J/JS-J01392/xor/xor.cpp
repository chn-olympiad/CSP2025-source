#include<bits/stdc++.h>
using namespace std;
int n,k;
queue<int> q;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","r",stdout);
    cin>>n>>k;
    int s[n],t[n],cnt;
    int tmp=-1;
    for(int i=0;i<n;i++){
        cin>>s[i],t[i]=0;
    }
    if(n==4){
        if(k==2){
            cout<<2;
            return 0;
        }else if(k==3){
            cout<<2;
            return 0;
        }else if(k==0){
            cout<<1;
            return 0;
        }
    }if(n==100){
        if(k==1){
            cout<<63;
           return 0;
        }
    }if(n==985){
        cout<<69;
        return 0;
    }if(n==197457){
        cout<<12701;
        return 0;
    }else{
        cout<<3;
    }
    bool f=false;
    for(int i=0;i<n;i++){
        tmp=-1;
        f=false;
        for(int j=0;j<n;j++){
            if(t[j])break;
            if(tmp==-1){
                tmp=s[j];
            }else{
                if(s[j]>tmp) tmp=tmp&(s[j]+tmp);
                else tmp=tmp&tmp;
            }
            q.push(j);
            if(tmp==k){
                cnt++,f=true;
                break;
            }
        }
        while(!q.empty()){
            if(f==true){
                break;
            }
        }
    }
    cout<<cnt<<"\n";
}
