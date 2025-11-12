#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[100010],sum=0;
    cin>>s;
    int n=s.size();
    for(int i=0;s[i];i++){
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
            sum++;
            a[sum]=s[i]-48;

        }
    }
    sort(a+1,a+sum+1);
    for(int i=sum;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
