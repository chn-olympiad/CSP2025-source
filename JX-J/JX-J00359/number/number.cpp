#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.length();
    int j=1;
    char a[l];
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
        }
    }
    int x=0;
    while(x!=j-1){
        int k=0,f;
        for(int i=1;i<=j-1;i++){
            if(a[i]>=k){
                k=a[i];
                f=i;
            }
        }
        char m=k;
        cout<<m;
        a[f]=0;
        x++;
    }
    return 0;
}
