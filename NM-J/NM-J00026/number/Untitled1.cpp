#include<bits/stdc++.h> 
using namespace std;
string s;
int op=0,cnt=0,ans=0,maxn,a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    op=s.size();
    for(int i =0;i < op;i ++){
        if(s[i]<=0||s[i]>= 9) cnt ++;
    }
    int q[cnt];
    for(int i =0;i < cnt;i ++){
        if(s[i]<=0||s[i]>= 9) q[ans]=s[i];
        ans ++;
    }
    while(cnt --){
        for(int i=0 ;i<ans ;i++){
            maxn=max(maxn,q[i]);
            if(q[i]=maxn)q[i]=0;
        }
        for(int i = 0;i<ans;i ++) {
            q[a]=maxn;
            a ++;
        }
        a=0;   
    }
    return 0;
}

