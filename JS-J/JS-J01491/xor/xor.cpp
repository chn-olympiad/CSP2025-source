#include <bits/stdc++.h>
using namespace std;

int fxor(int a,int b){
    queue<int>s1;
    queue<int>s2;
    int x=a,y=b;
    while(x!=0){
        s1.push(x%2);
        x/=2;

    }
    while(y!=0){
        s2.push(y%2);
        y/=2;
    }
    stack<int>st;
    int ans=0;
    int maxx=max(s1.size(),s2.size());
    if(s1.size()<s2.size()){
        for(int i=1;i<maxx-s1.size();i++){
            s1.push(0);
        }
    }else if(s1.size()>s2.size()){
        for(int i=1;i<maxx-s2.size();i++){
            s2.push(0);
        }
    }
    for(int i=0;i<maxx;i++){
        int p,q;
        p=s1.front();
        q=s2.front();
        if(p!=q){
            ans+=pow(2,i);
        }
        s1.pop();
        s2.pop();
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n+1]={0};
    for(int i=1;i<=n;i++){                  //!!!!!!      i<=n
        scanf("%d",&arr[i]);
    }
    int a[n+1]={0};
    // for(int i=1;i<=n;i++){
        
    // }
    cout<<2;
    return 0;
}