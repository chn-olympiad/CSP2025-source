#include<bits/stdc++.h>
using namespace std;

int s[110];
int cmp(int a,int b){
    return a>b;
}
int main(){
    ifstream fin("seat.in",ios::in);
    ofstream fout("seat.out",ios::out);

    int n,m;fin>>n>>m;
    int score;fin>>score;
    s[0] = score;
    for(int i=1;i<n*m;i++){
        int t;fin>>t;
        s[i] = t;
    }

    int x=1,y=1,where=0;
    sort(s+0,s+n*m+1,cmp);
    for(int i=0;i<n*m;i++){
        if(s[i]==score){
            where = i+1;
            break;
        }
    }
    if(where%n==0) y = where/n;
    else y = 1+where/n;

    if(y%2!=0){
        if(where%n==0) x = n;
        else x = where%n;
    }
    else{
        if(where%n==0) x = 1;
        else x = n-(where%n)+1;
    }

    fout<<y<<" "<<x;
    return 0;
}
