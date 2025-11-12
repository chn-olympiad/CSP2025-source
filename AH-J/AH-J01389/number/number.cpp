#include<bits/stdc++.h>
using namespace std;
string s;
long long mysize,n,a[1000100],t[100],p,k=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    mysize=s.size();
    for(long long i=0;i<mysize;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=s[i]-'0';
            t[a[k]]++;
            k++;
        }
    }
    for(int i=9;i>=0;i--){
        while(t[i]--){
            cout<<i;
        }
    }
    return 0;
}
