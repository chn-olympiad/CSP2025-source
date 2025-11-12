#include <bits/stdc++.h>

using namespace std;
string s;
char a[1000000+2];
long long int n;
int cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i];
        }else{
            ;
        }

    }
    sort(a,a+n,cmp);

    for(int i=0;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}
