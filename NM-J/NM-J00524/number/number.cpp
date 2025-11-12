#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    long long ans =0;
    long long num [10]={0,0,0,0,0,0,0,0,0,};
    cin>>a;
    cout<<a.length();
    for (long long i=0;i<a.length();i=i+1){
        if(isdigit(a[i])){
            num[a[i]-'0']++;
        }
    }
    for (int i=9;i<=0;i--){
            for(int j=1;j<=num[i];j++){
                cout<<ans;
            }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
