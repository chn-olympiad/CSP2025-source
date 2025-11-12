#include <bits/stdc++.h>
using namespace std;
bool c(int a,int b){
if(a>=b){
    return a;
}
return 0;
}
int main(){
freopen("seat.in","r",stin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[105]={};
for(int i=1;i<=n*m;i++){
    cin>>a[i];
}
int sum=a[1];
sort(a+1,a+n*m+1,c);
for(int i=1;i<=n*m;i++){
    if(a[i]==sum){
        if(i%n>0){
            if((i/n+1)%2==0){
                cout<<i/n+1<<" "<<n-i%n+1;
            }
            else{
                cout<<1+i/n<<" "<<i%n;
                }}
         else{
            if((i/n)%2==0){
                cout<<i/n<<" "<<1;
            }
            else{
                cout<<i/n<<" "<<n;
            }
         }


        break;
}

}



fclose(stdin);
fclose(stdout);
return 0;
}
