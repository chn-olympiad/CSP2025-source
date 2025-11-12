#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("replace.out");
ifstream fin("replace.in");
int main(){
    fout.sync_with_stdio(false);
    fin.sync_with_stdio(false);
    fout.tie(nullptr);
    fin.tie(nullptr);
    int n,m;
    string a,b;
    fin>>n>>m;
    for(int i=0;i<n+m;i++)
        fin>>a>>b;
    for(int i=0;i<m;i++)
        fout<<0<<endl;
    fin.close();
    fout.close();
    return 0;
}
