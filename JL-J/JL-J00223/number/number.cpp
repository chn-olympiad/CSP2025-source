#include<bits/stdc++.h>
using namespace std;
int a[10000100],k=1;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[k]=int(s[i]-'0');
            k++;
        }
    }
    sort(a+1,a+k,greater<int>());
    for(int i=1;i<k;i++){
        printf("%d",a[i]);
    }
    return 0;
}
