#include<bits/stdc++.h>
using namespace std;
string s;
int a[20],maxn=-1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
        maxn=max(maxn,s[i]-'0');
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            if(maxn!=0) printf("%d",i);
        }
    }
    if(maxn==0) printf("0");
    return 0;
}
