#include<bits/stdc++.h>
#define Maxn 1000000+10
using namespace std;
string s;
int a[Maxn],n=1;
void free(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
}
int main(){
    free();
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[n]=s[i]-'0';n++;
        }
    }
    sort(a+1,a+n);
    for(int i=n-1;i>0;i--)
        printf("%d",a[i]);
    return 0;
}
