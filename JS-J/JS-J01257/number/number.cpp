#include<bits/stdc++.h>
using namespace std;
string s;int a[1000001],ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.length(),j=0;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            j++;
            a[j]=s[i]-'0';
        }
    }
    sort(a+1,a+j+1);
    for(int i=j;i>=1;i--)
        printf("%d",a[i]);
}
