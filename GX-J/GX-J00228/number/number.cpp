#include<bits/stdc++.h>
using namespace std;
string s;
int l,a[10000001];
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    for(int i=0;i<=len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++l]=int(s[i]-'0');
        }
    }sort(a+1,a+l+1,cmp);
    for(int i=1;i<=l;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
}
