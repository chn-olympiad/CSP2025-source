#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
string a;
int s[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int t = 1;
    for(long long i = 0;i<=a.size()-1;i++){
        if(a[i]>='0'&&a[i]<='9'){
            s[t] = a[i]-'0';
            t++;
        }
    }
    sort(s+1,s+t);
    for(int i = t-1;i>=1;i--){
        cout<<s[i];
    }

    return 0;
}
