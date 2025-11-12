#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char num[1000005];
    cin>>s;
    int l=s.size();
    for(int i=0;i<=l;i++){
        if(s[i]-'0'>=0 && '9'-s[i]>=0){
            num[i]=s[i];
    }
}
    sort(num,num+l);
    for(int i=l-1;i>=0;i--){
        cout<<num[i];
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
