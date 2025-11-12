#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100],l,c=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[c]=s[i]-'0';
            c++;
        }
    }
    sort(a,a+c);
    for(int i=c-1;i>=0;i--)cout<<a[i];
    return 0;
}
