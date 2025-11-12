#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
char a[1000005];
int b=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;s[i]!='\0';i++){
        a[i]=s[i];
    }
    sort(a,a+s.size());
    for(int i=0;s[i]!='\0';i++){
        b=i+1;
        if(a[i]>='a'&&a[i]<='z') {
            b--;
            break;
        }
    }
    for(int i=b-1;i>=0;i--){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
