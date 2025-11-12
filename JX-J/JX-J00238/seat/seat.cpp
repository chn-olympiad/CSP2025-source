#include<bits/stdc++.h>
using namespace std;



int seat[11][11]={};









bool cmp(int x,int y){

    return x>y;





}



int main(){


    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);




    int n,m;
    cin>>n>>m;
    int text[101]={};
    for(int i=1;i<=n*m;i++){
        cin>>text[i];
    }

    int me=0;
    me=text[1];

    sort(text+1,text+1+n*m,cmp);




    //for(int i=1;i<=n*m;i++){
    //    cout<<text[i]<<' ';
    //}




    //cout<<endl;
/*
    int i1=1;
    int j1=1;
    for(int i=1;i<=n*m;i++){

        if((i/m+1)%2!=0){
            seat[j1][i1]=text[i];
            i1++;
        }
        else{
            seat[j1][n-i1]=text[i];
            i1++;
        }


        if(i1-1==n){
            j1++;
            i1=1;
        }




    }




    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<seat[i][j]<<' ';
        }
        cout<<endl;
    }



    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(seat[j][i]==me){
                cout<<j<<' '<<i;
                return 0;
            }
        }
    }

*/
    int i1=0;/*hang*/
    int j=1;/*lie*/
    int flag=0;
    for(int i=1;i<=n*m;i++){
       if(flag==1){
            i1--;

       }
       else{
            i1++;
       }

       if(i1==n){
            flag=1;
            j++;

       }
       else if(i1==0){
            flag=0;
            j++;
       }
       if(text[i]==me){
           if(flag==1){
                i++;

           }
           else{
                i--;
           }
           cout<<i1<<' '<<j1;
           return 0;
       }
    }




    return 0;







}
