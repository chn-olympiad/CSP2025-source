#include<bits/stdc++.h>
using namespace std;
string s;
int k,a[1000010];
bool cmp(int xn,int yn){
    return xn>yn;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long l=s.size()-1;
    for(long long i=0;i<=l;i++){
        if(s[i]>='0'&&s[i]<='9')
            a[++k]=s[i]-'0';
    }
    sort(a+1,a+k+1,cmp);
    if(a[1]==0){
        cout<<0;
    }
    else{
        for(int i=1;i<=k;i++){
            cout<<a[i];
        }
    }
    cout<<endl;
    return 0;
}
