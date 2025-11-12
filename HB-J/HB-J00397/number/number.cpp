#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}int a[100009]={0};
int main(){
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    int q[100005]={0},m;
    for(int i=0;i<lengh(a);i++){
        for(int j=0;j<lengh(a);j++){
            if(a[i]<10){
                if(q[j]==0){
                    q[j]=int(a[i]);
                    m+=1;
                    break;
                }
            }
        }

    }sort(q,q+1);
    cout<<q[0];

    return 0;
}
