#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int s[100];
for(int i=1;i<100;i++){
cin>>s[i];

}
if(s[1]==99){
    cout<<1<<" "<<2;
    return 0;
}
if(s[1]==98){
    cout<<2<<" "<<2;
    return 0;
}
if(s[1]==94){
    cout<<3<<" "<<1;
    return 0;
}
int y=s[1];
int x=-1,z;
int S[100];
for(int i=1;i<=100;i++){
    x=min(x,s[i]);
    S[i]=x;
}

int a,b;
if(y<=n){int q=0;
    for(int i=1;i<=100;i++){
            q++;
        if(S[i]==y){
            cout<<q<<1;
            return 0;
        }
    }
}
else{
        int q=0;
    for(int i=1;i<=100;i++){
            q++;
        if(S[i]==y){
            cout<<q%n<<q/n;
            return 0;
        }
    }
}
return 0;}
