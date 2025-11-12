#include<bits/stdc++.h>

using namespace std;
int a[1000005]{};

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    getline(cin,s);

    int b=1;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[b]=s[i]-'0';
            b++;
        }
    }
    sort(a,a+b);
    for(int i=b-1;i>0;i--){
        printf("%d",a[i]);
    }

    return 0;
}
