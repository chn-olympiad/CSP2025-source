#include <bits/stdc++.h>
using namespace std;
char a[1000001];
string x;
bool cmp(char x,char y){
    return y<x;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x;
    int j=0;
    for(int i=0;i<x.size();i++){
        if(isdigit(x[i])){
            a[j]=x[i];
            j++;
        }
    }sort(a,a+j,cmp);
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
