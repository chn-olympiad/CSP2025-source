#include<bits/stdc++.h>
using namespace std;
bool f=0;
string s;
long long cnt,a[1000050];
long long cmp(int x,int y){
    return y<x;
}
int main(){
    freopen("member.in","r",stdin);
    freopen("member.out","w",stdout);
    cin>>s;
    cnt=0;
    for(long long  i=0;i<=s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[cnt++]=s[i]-'0';
        }
    }
    for(long long i=0;i<cnt;i++){
        if(a[i]!=0){
            f=1;
        }
    }
    if(f==0){
        cout<<0;
        return 0;
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
