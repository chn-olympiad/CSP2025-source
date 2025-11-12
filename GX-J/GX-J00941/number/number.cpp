#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int k=0;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c>='0'&&c<='9'){
            a[k]=c-'0';
            k++;
        }
    }
    sort(a,a+k,cmp);
    for(int i=0;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
