#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010],sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number,out","w",stdout);
    cin>>s;
    for(int i=0;i<sizeof(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[sum]=s[i]-'0';
            sum++;
        }
    }
    sort(a,a+sum);
    for(int i=sum-1;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
