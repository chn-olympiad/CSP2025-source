#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,m;
    cin>>n>>m;
    string str[n];
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
    }
    int num=0;

    for(int i=0;i<n;i++){
       if(str[i]=="1"){
           num++;
       }
    }
    cout<<num;
    return 0;
}
