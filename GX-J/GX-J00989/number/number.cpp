#include<bits/stdc++.h>
using namespace std;
string s;
char num[1000005];
int n=0,m;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<sizeof(s);i++){
        if(s[i]>=39&&s[i]<=65){
            cout<<s<<" "<<s[i]<<";";
            num[n]=s[i];
            n++;
        }
    }
    for(int i=0;i<sizeof(s);i++){
        for(int j=0;j<sizeof(s);j++){
            if(num[j]<num[j+1]){
                m=num[j];
                num[j]=num[j+1];
                num[j+1]=m;
            }
        }
    }
    for(int i=0;i<sizeof(s);i++) cout<<num[i];
    return 0;
}
