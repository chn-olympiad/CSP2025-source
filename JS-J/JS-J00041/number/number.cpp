#include <bits/stdc++.h>
using namespace std;

int numbers[1000000];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int sum=0,t;
    for(int i=0;i<s.size();i++){
        t=s[i]-'0';
        if(t>=0 && t<=9){
            numbers[sum]=t;
            sum++;
        }
    }
    sort(numbers,numbers+sum,greater<int>());
    for(int i=0;i<sum;i++){
        printf("%d",numbers[i]);
    }
    return 0;
}