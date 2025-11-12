#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;cin>>n;
    int number[n.size()];
    for(int i=0;i<n.size();i++){
            number[i]=-1;
        if(n[i]>='0' & n[i]<='9')number[i]=(int)n[i]-48;
    }
    for(int i=0;i<n.size();i++){
        for(int j=0;j<n.size()-1-i;j++){
            if(number[j]<number[j+1]){
                int temp=number[j];
                number[j]=number[j+1];
                number[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n.size();i++){
        if(number[i]!=-1)cout<<number[i];
    }
    return 0;
}
