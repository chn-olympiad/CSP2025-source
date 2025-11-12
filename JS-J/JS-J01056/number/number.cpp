#include<bits/stdc++.h>
using namespace std;
string a[1000010];
int b[15];
int c[1000010];
int main(){
    freopen("number.in",'r',stdin);
    freopen("number.out",'w',stdout);
    for(int i=1;i<1000010;i++){
        cin>>a[i];
    }
    for(int i=1;i<1000010;i++){
        if(a[i]=="0") b[0]+=1;
        if(a[i]=="2") b[1]+=1;
        if(a[i]=="2") b[2]+=1;
        if(a[i]=="3") b[3]+=1;
        if(a[i]=="4") b[4]+=1;
        if(a[i]=="5") b[5]+=1;
        if(a[i]=="6") b[6]+=1;
        if(a[i]=="7") b[7]+=1;
        if(a[i]=="8") b[8]+=1;
        if(a[i]=="9") b[9]+=1;
    }
    int j=1;
    for(int i=9;i>=0;i--){
        while(b[i]>0){
            c[j]+=i;
            j+=1;
            b[i]-=1;
        }
    }
    for(int i=1;i<=j;i++){
        cout<<c[i];
    }
    return 0;
}
