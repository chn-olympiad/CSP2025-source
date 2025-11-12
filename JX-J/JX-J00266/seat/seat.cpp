#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int w,h;
    cin>>w>>h;
    int flag=1;
    //int maze[1000][1000]={0};
    int li[1000001]={0};
    for(int i=0;i<w*h;i++)cin>>li[i];
    int xiaoming = li[0];
    sort(li,li+w*h,greater<int>());
    int x=1,y=1,cnt=0;
    while(1){
        /*maze[x][y] = li[cnt];
        if(x<=w&&x>0){
            if(y%2)x++;
            else x--;
        }
        else y++;*/
        if(li[cnt]==xiaoming){
            cout<<y<<" "<<x;
            return 0;
        }
        //cout<<cnt<<endl;
        cnt++;
        int nx=x+flag;
        if(nx<=w && nx>0){
            x+=flag;
        }else if(x==w&&flag==1 || x==1&&flag==-1){
            y++;
            flag*=-1;
        }
    }
    return 0;
    //g++ -O2 -std=c++14 number.cpp -o number
}