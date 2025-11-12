#include <bits/stdc++.h>
using namespace std;

int sum[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    for (int i=0;i<n;i++){
        if (s[i]>='0' && s[i]<='9'){
            sum[s[i]-'0']++;
        }
    }
    bool f=0;
    for (int i=9;i>=0;i--){
        while (sum[i]>0 && i!=0){
            f=1;
            printf("%d",i);
            sum[i]--;
        }
        while (sum[i]>0 && i==0 && f){
            printf("%d",i);
            sum[i]--;
        }
        if (sum[i]>0 && i==0 && !f){
            printf("%d",i);
            sum[i]--;
        }
    }
    return 0;
}
