#include <bits/stdc++.h>
using namespace std; 

string s;
const int n=1e6;
char num[n];
int cnt=0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s; 
    for(int i=0;i<=n;i++){ 
        if(((int)s[i]>=48)&&((int)s[i]<=57)){
            num[cnt]=s[i];
            cnt++;
        }
    }
    sort(num,num+cnt);
    for(int j=cnt-1;j>=0;j--){
        cout<<num[j];
    }
    fclose(stdin);
    fclose(stdout); 
    return 0;
}