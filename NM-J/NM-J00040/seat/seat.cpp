#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,a1,x=1,y=1,m1=1;
    cin>>n>>m;
    vector<bool>b(101,0);
    cin>>a;
    for(int i=0;i<n*m-1;i++){
        cin>>a1;
        b[a1]=1;
    }
    //cout<<a;
    for(int i=100;i>a;i--){
        if(b[i]){
            if((m1==1&&y<n)||(m1==-1&&y>1))y+=m1;
            else{x++;m1=-m1;}
        }
    }
    cout<<x<<' '<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
