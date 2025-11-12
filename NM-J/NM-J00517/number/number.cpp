#include<bits/stdc++.h>
using namespace std;

int main(){
     freopen("number.out",'w',"stdout");
     freopen("number.in",'r',"stdin");
    
    string s;
    cin>>s;
    int a = s.size(),n;
    int q[a];
    for (int i = 0; i < a; i++)
    {
        if((s[i] <='9' && s[i] >='1') || s[i] =='0') {
            q[i] = s[i];
        }
        else q[i] = 10;
    }
    for (int i = 0; i < a; i++){
        for (int i = 0; i < a-1; i++){
            if(q[i] == 10) continue;
            if(q[i] < q[i+1]){
                n = q[i];
                q[i] = q[i+1];
                q[i+1] = n;
            }
        }
    }
    for (int i = 0; i <= a; i ++)
    {
        if(q[i] = 10) continue;
        cout<<q[i];
    }
    
    
     
    return 0;
}