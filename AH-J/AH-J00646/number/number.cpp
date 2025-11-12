#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000000],j=0;
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    for(int k=0;k<j-1;k++){
        for(int l=0;l<j-1-k;l++){
            if(a[l]<a[l+1])
              swap(a[l],a[l+1]);
    }
}
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
