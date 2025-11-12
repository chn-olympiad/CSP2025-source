#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int num[100];
char a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int len = strlen(a);
    for(int i = 0;i <= len-1;i++){
        if(a[i]>='0'&&a[i]<='9'){
            int tmp = a[i]-'0';
            num[tmp]++;
        }
    }
    bool flag = 0;
    for(int i = 1;i <= 9;i++){
        if(num[i]!=0) flag = 1;
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
    for(int i = 9;i >= 0;i--){
        for(int j = 1;j <= num[i];j++){
            cout<<i;
        }
    }
    return 0;
}
