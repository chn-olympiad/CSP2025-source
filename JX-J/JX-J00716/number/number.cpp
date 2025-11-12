#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1001],b=0,k=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=58){
            a[k]=s[i]-'0';
            k++;
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<k-i;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=0;i<k;i++){
        b=b*10+a[i];
    }
    cout<<b;
    return 0;
}
