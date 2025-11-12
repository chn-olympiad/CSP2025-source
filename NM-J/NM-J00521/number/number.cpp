#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    long long num[10]={0,0,0,0,0,0,0,0,0};
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for (long long i=0;i<a.length();i=i+1){
        if(isdigit(a[i])){
			num[a[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=num[i];j++){
            cout<<i;
        }
    }

    return 0;
}
