#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],b;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            b++;
            a[b]=s[i]-'0';
        }
    }
    sort(a+1,a+b+1);
    for(int i=b;i>=1;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
