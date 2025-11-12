#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    if (x>y){
        return true;
    }
    else {
        return false;
    }
}
int main(){
int m,n,a;
cin >> n >> m;
int s[100];
for (int i=0;i<(m*n);i++){
    cin >> s[i];
}
a=s[0];
int b;
sort(s,s+(m*n),cmp);
for (int i=0;i<(m*n);i++){
    if (a==s[i]){
        if(i<n){
            b=i+1;
        }
        else{
            b=i/n+1;
        }
        cout << (i/n+1) << " " << b;
    }
}
    return 0;
}
