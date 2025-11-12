#include<bits/stdc++.h>
using namespace std;
int S;
int s[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>S;
    int n=0;
    while(S!=0){
        s[n]=S%10;
        S/=10;
        n++;
    }
    sort(s,s+n);
    for(int i=n-1;i>=0;i--){
        cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
