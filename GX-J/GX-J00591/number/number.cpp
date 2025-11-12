#include<bits/stdc++.h>
using namespace std;
long long arr[10];
string num;
int main(){
    freopen("number1.in","r",stdin);
    freopen("number1.out","w",stdout);
    cin >> num;
    for(int i=0;i<num.length();i++){
        if(num[i]>='0' && num[i]<='9'){
            arr[num[i]-'0']++;
        }
    }
    for(int j=9;j>=0;j--){
        for(int k=arr[j];k>0;k--){
            printf("%i",j);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
