#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[10000001];
int v[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<strlen(a);i++)if('0'<=a[i]&&a[i]<='9')v[a[i]-'0']++;
    bool t=0;
    for(int i=1;i<=9;i++){
        if(v[i]){
            t=1;
            break;
        }
    }
    if(!t){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=v[i];j++){
            cout<<i;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
