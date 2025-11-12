#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s;
int a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            int k=s[i]-'0';
            a[k]++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]){
            printf("%d",i);
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
