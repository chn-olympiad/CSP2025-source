#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen(number.in,'r',stdin);
    freopen(number.out,'w',stdout)
    string  n,m;
    int cnt=0,max1=0;
    getline(cin,n);
    m=strlen(n);
    for(char i=n;i<m;i++){
        if(isdigit(n(i))){
           cnt=stoi(i);
           if(cnt>max1){
            max1=cnt;
           }
           n.clear();
        }
    }
    cout<<max1;
    return 0;
}
