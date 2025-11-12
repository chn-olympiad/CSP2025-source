#include<bits/stdc++.h>
using namespace std;
long long n[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(isdigit(a[i])) n[a[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(long long j=1;j<=n[i];j++) cout<<i;
        //cout<<n[i]<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
