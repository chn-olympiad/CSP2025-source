#include<bits/stdc++.h>
using namespace std;
string s[1010];
string b[1010];
int main(){
    freopen("number.in","r",stdin);
     freopen("number.out","w",stdin);
    for(int i=1;i<=1010;i++){
         cin>>s[i];
        for(int j=9;j>=0;j++){
            b[j]=j;
           if(s[i]==b[j]){
               cout<<s[i];
        j--;
        return 0;

            }
        }
    }
fclose(stdin);
fclose(stdout);
        return 0;
    }

