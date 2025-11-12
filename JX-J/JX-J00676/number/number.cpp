#include<bits/stdc++.h>
using namespace std;
int a[1000010];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int x=s.size();
    int j=0;
    for(int i=0;i<x;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-48;
            j++;
        }
    }
    sort(a,a+j);
    for(int i=j-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}


