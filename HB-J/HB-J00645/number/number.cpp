#include<bits/stdc++.h>
using namespace std;
char c[100005];
int a=0,b[100005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.getline(c,100005);
    int len=strlen(c);
    for(int i=0;i<len;i++){
        if(c[i]>='0'&&c[i]<='9'){
            a++;
            b[a]=c[i]-'0';
        }
    }
    sort(b+1,b+a+1);
    for(int i=a;i>=1;i--)  cout<<b[i];
    return 0;
}
