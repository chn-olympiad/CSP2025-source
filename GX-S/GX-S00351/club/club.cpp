#include<bits/stdc++.h>
using namespace std;
int t,n,a[100003][3],x,y,z,ans;
int d(int deep,int t){
    if(deep==n)return t;
    //if((x+1)<=(n/2)&&(y+1)<=(n/2)&&(z+1)<=(n/2))return 0;
    x++;
    int s1=d(deep+1,t+a[deep][0]);
    x--;
    y++;
    int s2=d(deep+1,t+a[deep][1]);
    y--;
    z++;
    int s3=d(deep+1,t+a[deep][2]);
    z--;
    //if((x+1)>(n/2)){
        //if(s2>s3){
        //    y++;
         //   return s2;
        //}else{
        //    z++;
        //    return s3;
       // }
    //}else if((y+1)>(n/2)){
      //  if(s1>s3){
      //      x++;
      //      return s1;
      //  }else{
     //       z++;
     //       return s3;
    //    }
  //  }else if((z+1)>(n/2)){
      //  if(s2>s1){
       //     y++;
        //    return s2;
        //}else{
         //   x++;
         //   return s1;
        //}
     //   return max(s1,s2);
    //}else{
        if(max(s1,max(s2,s3))==s1){
            x++;
            return s1;
        }else if(max(s1,max(s2,s3))==s2){
            y++;
            return s2;
        }else{
            z++;
            return s3;
        }
    //}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        x=y=z=ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        cout<<d(0,0)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0*/
