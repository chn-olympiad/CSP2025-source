#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    int a[11]={0};
    for(int i=0;i<str.size();i++){
        if(str[i]>='0'&&str[i]<='9'){
            a[str[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]>0){
            cout<<i;
            a[i]--;
        }
    }
    cout<<'\n';
   fclose(stdin);
   fclose(stdout);
   return 0;
}
