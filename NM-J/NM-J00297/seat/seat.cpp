#include<bits/stdc++.h>
using namespace std;
bool q(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    int c[100];
    for(int i=0;i<n*m;i++){
        cin>>c[i];
    }
    int w=c[0];
    sort(c,c+m*n,q);
    int x=0,y=0;
    int o=0;
    for(int i=0;i<m*n;i++){
        if(c[i]==w){
            cout<<x+1<<' '<<y+1;
            break;
        }
        if((i+1)%n==0){
            x++;
        }
        if(x%2==0){
            y++;
        }
        else{
            y--;
        }


    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
