#include<bits/stdc++.h>
using namespace std;
const int N=100000000;
string s;
int a[N+1],pos=0,num;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        if('0'<=s[i] and s[i]<='9'){
            num=s[i]-'0';
            a[pos]=num;
            pos++;
        }
        for(int j=0;j<pos-1;j++){
            for(int k=j;k<pos-1;k++){
                if(a[k]<a[k+1]){
                    swap(a[k+1],a[k]);
                }
            }
        }
    }
    for(int i=0;i<pos;i++){
        cout<<a[i];
    }
    return 0;
}
