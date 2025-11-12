#include <bits/stdc++.h>

using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int listb[m][n]={0};
    int lista[n*m];
    int specl=0;
    for(int i=0;i<n*m;i++){
        cin>>lista[i];
    }
    specl=lista[0];
    sort(lista,lista+n*m,cmp);
    int up=0,x=0,y=0;
    for(int i=0;i<n*m;i++){
        listb[x][y]=lista[i];

        if(lista[i]==specl){
            cout<<x+1<<' '<<y+1;
        }
        if(up==0 ){
            if(y+1>n-1){
                x++;
                up=1;
            }
            else{
                y+=1;
            }
        }
        else if(up==1){
            if(y-1<0){
                x++;
                up=0;
            }
            else{
                y-=1;
            }
        }
    }
    cout<<endl;
    return 0;
}
