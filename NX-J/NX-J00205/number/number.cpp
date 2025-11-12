#include<bits/stdc++.h>
using namespace std;
int main(){
    int s[1000]={0},n=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(s){
        cin>>s[n];
        n++;
    }
    int e;
    for(int j=1;j<=n;j++){
        for(int i=0;i<n;i++){
            if(s[i]<s[i+1]){
                e=s[i];
                s[i]=s[i+1];
                s[i+1]=e;
            }
        }
    }
    for(int i=0;i<=n;i++){
        cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
