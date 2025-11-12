#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=1;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
        }
    }
    sort(a+1,a+j+1);
    for(int i=j;i>=1;i--){
        cout<<char(a[i]);
    }
    return 0;
}
