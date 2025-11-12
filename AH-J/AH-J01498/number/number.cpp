#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);
    int c=s.length();
    int a[c+1]={0},b=1;
    for(int i=0;i<c;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[b]=s[i]-'0';
            b++;
        }
    }
    sort(a+1,a+1+c);
    for(int i=c;i>c-b+1;i--)cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
