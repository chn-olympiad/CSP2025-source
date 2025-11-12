#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,x=1,y=1,k=1;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
    cin>>a[i];
    b[i]=i;
}
for(int i=1;i<=n*m;i++){
    for(int j=1;j<n*m;j++){
        if(a[j]<a[j+1]){
            swap(a[j],a[j+1]);
            swap(b[j],b[j+1]);
        }
    }
}

while(b[k]!=1){
    if(y%2==0){
        if(x==1){
            y++;
        }
        else{
            x--;
        }
    }
    else{
        if(x==n){
            y++;
        }
        else{
            x++;
        }
    }
    k++;
}
cout<<y<<" "<<x;
fclose(stdin);
fclose(stdout);
return 0;
}
