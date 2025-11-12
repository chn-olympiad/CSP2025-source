#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int ans=0;
bool px(int a,int b){
    return a>b;
}
int main(){

    cin>>s;
    int n=s.size();
    for(int i=0;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans++;
            a[ans]=s[i]-'0';
        }
    }
    sort(a+1,a+ans+1,px);
    for(int i=1;i<=ans;i++){
        cout<<a[i];
    }


    return 0;
}
