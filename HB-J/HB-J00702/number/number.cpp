#include<bits/stdc++.h>
using namespace std;
int ad(int x,int y){
    for(int i=1;i<=x;i++){
        y*=10;
    }
    return y;
}
int main(){
    char s[1000005];
    cin>>s;
    int l=strlen(s);
    int n[1005],m=0,ll=0,ling=0;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            ll++;
            n[ll]=s[i]-'0';
        }
    }

    for(int j=1;j<=ll;j++){
        for(int i=1;i<=ll-1;i++){
            if(n[i]>n[i+1]) swap(n[i],n[i+1]);
        }
    }
    int ans=0,a;
    for(int i=1;i<=ll;i++){
        a=ad(i-1,n[i]);
        ans+=a;
    }
    cout<<ans;
    return 0;
}
