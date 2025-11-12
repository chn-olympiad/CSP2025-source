#include<bits/stdc++.h>
using namespace std;
int a[15]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int x=s.size();
    for(int i=0;i<x;i++){
        a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
