#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number1.in","r",stdin);
    freopen("number1.out","w",stdout);
    string s;
    cin>>s;
    long long a[100000],sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<'a'){
            a[sum]=s[i]-'0';
            sum++;
       }
    }
    sort(a,a+sum);
    for(int i=sum-1;i>=0;i--){
            cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
