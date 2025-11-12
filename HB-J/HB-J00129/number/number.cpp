#include<bits/stdc++.h>
using namespace std;
int main()
{

    string s;
    cin>>s;
    char a[1000010]={0};
    int n=0;
    for(int i=1;i<=s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[n]=s[i];
            n++;
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            if(a[j]<a[j+1])
                swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<n-1;i++){
        printf("%d",a[i]-'0');
    }
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    return 0;
}

