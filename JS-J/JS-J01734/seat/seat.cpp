#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("seat.in");
    ofstream fout("seat.out");

    int n,m,rs,ri=0;
    fin>>n>>m;
    vector<int>score(n*m,0);
    for(int i=0;i<n*m;i++){
        fin>>score[i];
    }
    rs=score[0];
    // cout<<rs;
    sort(score.begin(),score.end());
    for(int i=0;i<n*m;i++){
        // cout<<score[i];
        if(score[i]==rs){
            // cout<<i;
            ri=i;break;
        }
    }
    ri=n*m-ri-1;
    // cout<<ri;

    fout<<ri/n+1<<" ";

    if(ri%(2*n)/n){
        // cout<<"a";
        fout<<n-(ri%n);
    }else{
        fout<<ri%n+1;
    }
    
    return 0;
}