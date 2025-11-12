#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int num[1000001];
    int j=0;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            num[j]=s[i]-'0';
            j++;
        }
    }
    sort(num,num+j);
    for(int i=j-1;i>=0;i--){
        cout<<num[i];
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}