#include <bits/stdc++.h>
using namespace std;
//finished for GX-J01153
bool sortrule(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int seat[m*n+4];
    int Rscore=0;
    cin>>Rscore;
    seat[0] = Rscore;
    for(int i=1;i<n*m;i++){
        cin>>seat[i];
    }
    sort(seat+0,seat+(n*m),sortrule);

    int Rseat=0;
    for(int i=0;i<n*m;i++){
        if(seat[i]==Rscore){
            Rseat = i;
            break;
        }
    }
    int Rn,Rm;//Rn is R's seat Hang,and Rm is Lie. Attention!!:output is Lie and Hang,not Hang and Lie
    Rn = Rseat/n;
    Rm = Rseat%n;
    cout<<"rm"<<Rm<<' '<<"Rn"<<Rn<<endl;
    Rn++;Rm++;
    if(Rn%2==0)Rm = n-Rm+1;

    cout<<endl<<Rn<<' '<<Rm;

    return 0;
}
