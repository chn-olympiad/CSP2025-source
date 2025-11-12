#include<bits/stdc++.h>
using namespace std;
string s;
long long int a[1000001],res;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]<='9'&&s[i]>='0'){
            res++;
            a[res]=s[i]-'0';
        }
    }
    sort(a+1,a+1+res,cmp);
    for(int i=1;i<=res;i++){
        cout << a[i];
    }
    return 0;
}
