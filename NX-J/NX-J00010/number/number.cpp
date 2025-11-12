#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000000]={0};
    int j=0;
    int x=0;
    int sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>'0' && s[i]<'9'){
            a[j]=int(s[i]-abs(9-'9'));
            j++;
        }
        if(s[i]=='0'){
            x++;
        }
    }
    int qwe=1;
    for(int i=0;i<1000000;i++){
        if(a[i]>=1 && a[i]<=9){
            sum+=a[i]*qwe;
            qwe*=10;
        }
    }
    cout<<sum;
    return 0;
}
