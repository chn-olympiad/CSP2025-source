 #include<bits/stdc++.h>
using namespace std;
string s;
long long a[1145]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i = 0;i<s.length();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    bool f = 0;
    for(int i = 9;i>0;i--){
        for(int j = 0;j<a[i];j++)cout<<i;
        if(a[i]!=0)f=1;
    }
   if(f==0){
        cout<<0;
    }else{
        for(int i = 0;i<a[0];i++)cout<<0;
    }
    return 0;
}
