#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+5;
string s;
long long a[mn],ans,l;
bool is_num(char x){
    return '0'<=x and x<='9';
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    // num
    for(int i=0;i<s.size();i++){
        if(is_num(s[i])){
            a[l++]=s[i]-'0';
        }
    }
    //sort  321
    for(int i=0;i<l-1;i++){
        for(int j=0;j<l-1;j++){
            if(a[j]<a[j+1]){
                int x=a[j];
                a[j]=a[j+1];
                a[j+1]=x;
            }
        }
    }
    for(int i=0;i<l;i++){
        // printf("%d ",a[i]);
        // ans+=a[i]*pow(10,i);
        printf("%lld",a[i]);
    }
    // printf("%lld\n",ans);
    printf("\n");
    return 0;
}