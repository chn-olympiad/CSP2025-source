#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string s;
    int a[n];
    int x=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=0)
            x++;
    }
    int answer=1;
    for(int i=2;i<=x;i++)
        answer*=i;
    if(x>=m)
        cout<<answer;
    else
        cout<<0;
    return 0;
}
