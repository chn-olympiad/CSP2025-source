#include<iostream>
using namespace std;
int a[10]={0};char c;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>c){
        if(c>='0'&&c<='9') a[(c-'0')]++;
    }
    for(int i=9;i>=0;i--){
        while(a[i]>0){
            cout<<i;
            a[i]--;
        }
    }
    return 0;
}
