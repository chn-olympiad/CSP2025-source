#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
int a,s,max;
cin>>a>>s;
int w[a][s];
max=w[0][0];
for(int i=0;i<a;i++){
    for(int j=0;j<s;j++){
        cin>>w[i][j];
    }

}

for(int i=0;i<a;i++){
    for(int j=0;j<s;j++){if(i%2==0){
        if(w[i][j]<w[i][j+1]){

                if(w[i][j]==w[i][s]){
                    swap(w[i][j],w[i+1][j]);
                }
                else{
                    swap(w[i][j],w[i][j+1]);
                }

        }}
        if(i%2==1){
        if(w[i][j+1]<w[i][j]){

                 if(w[i][j]==w[i][s]){
                    swap(w[i][j],w[i+1][j]);
                }
                else{
                    swap(w[i][j+1],w[i][j]);
                }
        }
        }}


}
for(int i=0;i<a;i++){
    for(int j=0;j<s;j++){
        if(w[i][j]==max){
        cout<<w[i][j];

        }
}
}

}
