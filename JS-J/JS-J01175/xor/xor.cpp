#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("xor.in");
    ofstream fout("xor.out");
    int n,k,b,c,s=0;
    vector<int> a;
    fin>>n>>k;
    for(int i=0;i<n;i++){
        fin>>b;
        a.push_back(b);
    }
    c=0;
    for(int i=0;i<n;i++){
        if(c==0){
            c=a[i];
        }
        else{
            if(a[i]==0){
                c=1;
            }
            else{
                c=0;
            }
        }
        if(c==k){
            c=0;
            s++;
        }
    }
    fout<<s;
    fin.close();
    fout.close();
    return 0;

}
