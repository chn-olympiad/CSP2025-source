#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);


    string s;
    cin>>s;
    char c[10^3];
    int x=0;
    for(int i=0;i<10^6;i++){
        while(x<10^6){
            if(s[x]==0||s[x]==1||s[x]==2||s[x]==3||s[x]==4||s[x]==5||s[x]==6||s[x]==7||s[x]==8||s[x]==9){
            c[i]==s[x];
            }
            x++;
        }
    }
    for(int i=0;i<10^3;i++){
        int max=c[i];
        for(int j=0;j<10^3-i;j++){
            if(c[max]<c[j]){
                int flag=c[max];
                c[max]=c[j];
                c[j]=flag;
            }
        }
    }
    for(int i=0;i<10^3;i++){
        cout<<c[i];
    }

    return 0;
}
