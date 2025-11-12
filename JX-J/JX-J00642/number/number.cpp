#include<bits/stdc++.h>
using namespace std;
const int MAX=1000005;
char s[MAX];
int a[1001],ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=(int)s[i];ans=i;
        }
    }
    sort(a,a+ans+1);
    for(int i=ans;i>=0;i--){
        cout<<(char)a[i];
    }
    return 0;
}
