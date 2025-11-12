#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    bool flag=false;
    cin>>s;
    char a[100];
    int sum=0;
    for(int i=1,j=1;i<=s.length();i++){
        if(s[i-1]>'0' && s[i-1]<='9') {
            a[i]=s[i-1];
            j++;
            sum++;
            flag=true;
        }if(s[i-1]=='0'){
            a[i]=s[i-1];
            j++;
            sum++;
        }
    }
    if(!flag){
        cout<<0;
        return 0;
    }if(sum==1){
       cout<<a[1];
        return 0;
    }
    for(int i=1;i<sum-1;i++){
        char max1=a[i];
        for(int j=i+1;j<sum;j++){
            if(int(max1)<int(a[j])){
                max1=a[j];
            }
        }
        cout<<max1;
        char me;
        me=max1;
        max1=a[i];
        a[i]=me;
    }
    cout<<a[sum];
    return 0;
}
