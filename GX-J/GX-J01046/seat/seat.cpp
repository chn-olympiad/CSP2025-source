#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    int s[10001];
    cin>>x>>y;
    for(int i=0;i<x+y;i++){
    cin>>s[i];
        sort(s+0,s+i+1);
        cout<<  s[i]  <<  " ";
    }
        return 0;
    }
