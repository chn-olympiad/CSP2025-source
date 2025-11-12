#include<bits/stdc++.h> 
using namespace std;
int a,b,c,d[a*b-1],op,po;
int q[a][b];
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>a>>b;
    cin>>c;
    
    for(int i=0;i<a*b-1;i ++){
        cin>>d[i];
    }
    op=(100-c)%b;
    po=(100-c)/b+1;
    cout<<op<<po; 
    return 0;
}

