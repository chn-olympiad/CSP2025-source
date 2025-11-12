#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s="123";
    cin>>s;
    int a=0;
    int w[10005]={0};
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            w[a]=int(s[i]-48);
            a++;
        }
    }
    sort(w,w+a);
    for(int i=a-1;i>=0;i--){
        cout<<w[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
