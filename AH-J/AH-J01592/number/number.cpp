#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int in=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[in++]=s[i]-'0';
        }
    }
    sort(a+1,a+in,cmp);
    for(int i=1;i<in;i++){
        printf("%d",a[i]);
    }
    return 0;
}
