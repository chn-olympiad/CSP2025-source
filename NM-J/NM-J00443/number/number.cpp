#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b;
int main(){
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[b]=s[i]-48;
            b++;
        }
    }
    sort(a,a+b);
    for(int i=b-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
