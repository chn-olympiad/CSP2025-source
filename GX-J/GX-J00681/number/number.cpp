#include<bits/stdc++.h>
using namespace std;
int a[1000100]={0},s=0;
void p(){
    int d;
    while(d==0){
        d=0;
        for(int i=0;i<s;i++){
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
                d++;
            }
    }
    }
}

int main(){
    string n;
    cin>>n;
    if(n.size()==1){
        cout<<n;
    }else{
        for(int i=0;i<n.size();i++){
            if(n[i]>='0' && n[i]<='9'){
                a[s]=n[i]-'0';
                s++;
            }
        }
        p();
        for(int i=0;i<s;i++){
            cout<<a[i];
        }
    }
    return 0;
}
