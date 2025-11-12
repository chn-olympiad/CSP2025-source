#include<bits/stdc++.h>
using namespace std;
const int N=10010;
string s;
int a[N];
int k=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[k]=s[i];
            k++;
        }
    }
    sort(a+1,a+1+k,cmp);
    for(int i=1;i<k;i++){
        cout<<(char)a[i];
    }
    return 0;
}
