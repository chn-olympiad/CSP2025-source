#include<bits/stdc++.h>
using namespace std;
int m,n;//hang lie

int a[1000005];
int h=0;
int main(){
freopen("seat","r",stdin);
freopen("seat","w",stdout);
cin>>m>>n;
int s=m*n;
for(int i=1;i<=s;i++){
    cin>>a[i];


    h=a[1];
}
for(int i=1;i<=s;i++){
   for(int j=i+1;j<=s;j++){
    if(a[i]<a[j]){
        swap(a[i],a[j]);
    }
   }
}
for(int i=1;i<=s;i++){
        if(m==1){
    if(a[i]==h){
        cout<<"1"<<" "<<i;
    }
    }

}

for(int i=1;i<=s;i++){

    if(m==2){

        while(a[i]==h){
            if(i>n){
                cout<<"2"<<" "<<2*n-i+1;
            }
            else{
                cout<<"1"<<" "<<i;
            }
            break;
        }
    }

}
return 0;
}
