#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    string s;
    cin>>s;
    fclose(stdin);
    int a[10]={0};
    for(int i=0;i<s.size();i++){
        if((s[i]>=48) && (s[i]<=57)){
            a[s[i]-48]++;
        }
    }
    freopen("number.out","w",stdout);
    for(int j=9;j>=0;j--){
        while(a[j]>0){
            cout<<j;
            a[j]--;
        }
    }
    fclose(stdout);
    return 0;
}
