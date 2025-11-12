#include<bits/stdc++.h>
using namespace std;
int a[1000005],n;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')a[++n]=s[i]-'0';
    }
    sort(a+1,a+n+1);
    if(a[n]==0){
        printf("0");
        return 0;
    }
    for(int i=n;i>=1;i--){
        printf("%d",a[i]);
    }
    return 0;
}
