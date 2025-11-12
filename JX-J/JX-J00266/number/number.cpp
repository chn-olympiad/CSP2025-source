#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string ch;
    cin>>ch;
    int cnt=0;
    char maze[2000000]={0};
    for(auto c : ch){
        if(c>='0' && c<='9')maze[cnt]=c,cnt++;
    }
    sort(maze,maze+cnt,greater<int>());
    for(int i=0;i<cnt;i++)cout<<maze[i];
    cout<<endl;
    return 0;
    //g++ -O2 -std=c++14 number.cpp -o number
    /*freopen("number4.in","r",stdin);
    freopen("number.out","w",stdout);
    string ch;
    char maze[2000000]={0};
    cin>>maze;
    int cnt=0;
    for(int i=0;i<strlen(maze);i++){
        if(maze[i]>='0' && maze[i]<='9')cnt++;
        else maze[i]=0;
    }
    sort(maze,maze+cnt,greater<int>());
    for(int i=0;i<cnt;i++)cout<<maze[i];*/
}