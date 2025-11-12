#include<bits/stdc++.h>
using namespace std;
string s;
char ch;
int a[10005],n=0;
int main(){
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]<='9'&&s[i]>=0){
            a[n]=s[i]-'0';
            n++;
        }
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }
return 0;
}
