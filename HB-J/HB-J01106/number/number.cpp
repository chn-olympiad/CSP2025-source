#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(len==1){
                cout<<s[i];
                return 0;
            }
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
