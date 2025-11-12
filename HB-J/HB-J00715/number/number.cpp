#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    long long a[1000005],b=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b++;
            a[b]=s[i]-'0';
        }
    }
    sort(a,a+1+b);
    if(a[b]==0){
        cout<<0;
        return 0;
    }
    for(int i=b;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
