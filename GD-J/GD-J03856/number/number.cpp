#include<iostream>
#include<fstream>
using namespace std;
char c;
int num[10],i; 
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>c) if(c>='0'&&c<='9') num[int(c-'0')]++;
    for(i=9;i>=0;i--) while(num[i]){cout<<i;num[i]--;}

    return 0;
}

