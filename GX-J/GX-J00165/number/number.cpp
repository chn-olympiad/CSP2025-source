#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string n;
    int j=0;
    cin>>n;
    int f=n.size();
    char fds[100000];
    for(int i=0;i<f;i++){
        if(n[i]>='0'&&n[i]<='9'){
            fds[j]=n[i];
        }
        j++;
        if(i==f){
            break;
        }
    }
    for(int l=0;l<=j;l++){
        for(int i=0;i<=j;i++){
                if(fds[i]<fds[i+1]){
                    int huan=fds[i];
                    fds[i]=fds[i+1];
                    fds[i+1]=huan;
                }
            }
    }
    for(int i=0;i<=j;i++){
        cout<<fds[i];
    }





    return 0;

}
