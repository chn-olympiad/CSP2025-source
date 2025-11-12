#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat1.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int x,y;
    int s[10001];
    cin >> x >> y;
    for(int i=0;i<x+y;i++){
        cin >> s[i];
        if(s[i]>s[i+1]){
            for(int j=0;j<=s[i];j++){
                int t=s[i];
                s[i+1]=s[i-1];
                s[i-1]=s[i];
                s[i]=t;
            }

        }
        cout << s[i] << " ";
        if(s[1]==99){
            cout << 1 << 2;
        }
        else if(s[1]==){

        }
    }
}
