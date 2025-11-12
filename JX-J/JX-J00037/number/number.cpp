#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000001];
    int sum=1;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[sum]=s[i]-'0';
            sum++;
        }
    }
    sort(a+1,a+sum+1);
    for(int i=sum;i>=2;i--){
        cout<<a[i];
    }
    return 0;
}
