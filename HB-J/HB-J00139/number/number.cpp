#include<bits/stdc++.h>
using namespace std;
int digit[11];
int main(){
    freopen("number.in","r",stdin);freopen("number.out","w",stdout);
    string str;
    cin>>str;
    for(int i=0;i<=str.size()-1;i++)
        if(str[i]>='0' && str[i]<='9')
            digit[str[i]-'0']++;
    for(int i=9;i>=0;i--){
        for(int j=1;j<=digit[i];j++){
            cout<<i;
        }
    }
    cout<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}