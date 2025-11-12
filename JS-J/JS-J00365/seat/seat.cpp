#include<bits/stdc++.h>
using namespace std;
int n,m,p,gl,type,idx=1,idy=1,sc[105],arr[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    p=n*m;
    for(int i=1;i<=p;i++){
        cin>>sc[i];
        if(i==1)gl=sc[i];
    }
    sort(sc+1,sc+1+p);
    while(idy!=m||m%2==1&&idx!=n||m%2==0&&idx!=1){
        arr[idx][idy]=sc[p];
        if(sc[p]==gl)break;
        if(type==0){
            idx++;
            if(idx==n)type=1;
        }
        else if(type==1){
            idy++;
            type=2;
        }
        else if(type==2){
            idx--;
            if(idx==1)type=3;
        }
        else{
            idy++;
            type=0;
        }
        p--;
    }
    cout<<idy<<' '<<idx;
    return 0;
}
