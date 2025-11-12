#include<bits/stdc++.h>
using namespace std;
int main(){
char s[100],a;
int n;
cin >> n;
for(int i=0;i<n;i++){
    cin >> s[char(i)];
}
int sum=0;
for(int i=0;i<n;i++){
    if (((s[i]>='1')||(s[i]<='9'))||((s[i+1]>='1')||(s[i+1]<='9'))){
        sum+=1;
        if(s[i]<s[i+1]){
            a=s[i];
            s[i]=s[i+1];
            s[i+1]=a;
        }
    }
}
for(int i=0;i<sum;i++){
        cout << s[i];
}
    return 0;
}
