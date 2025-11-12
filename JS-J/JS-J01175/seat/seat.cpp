#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("seat.in");
    ofstream fout("seat.out");
    int n,m;
    vector<int> a;
    int b;
    fin>>n>>m;
    for(int i=0;i<n*m;i++){
        fin>>b;
        a.push_back(b);

    }
    b=a.front();
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i*n+j]==b){
                if(i%2==0){
                    fout<<i+1<<' '<<j+1;
                }
                else{
                    fout<<i+1<<' '<<n-j;
                }
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}



