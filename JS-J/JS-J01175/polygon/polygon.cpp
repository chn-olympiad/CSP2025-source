#include<bits/stdc++.h>
using namespace std;
int s=0,m=0,cou=0;
vector<int> a;
vector<int> p;
int c(vector<int> p){
    s=0;
    m=0;
   for(int i:p){
    s+=i;
    m=max(m,i)
   }
    if(s>m*2 and d-c>=2){
        return 1;
    }
    else{
        return 0;
    }
}
int sh(int f,int e){
    if(p.size()>=f){
        if(c(vector<int> p)){
           cou++;
        }
        return 0;
    }
    for(int i=e+1;i<n;i++){
        p.push_back(a[i]);
        sh(f,e);
        p.pop_back();
    }
}
int main(){
    ifstream fin("polygon.in");
    ofstream fout("polygon.out");
    int n,b;
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>b;
        a.push_back(b);
    }
    for(int i=3;i<=n;i++){
        sh(i,-1);
    }
    fout<<cou%998244353;
    fin.close();
    fout.close();
    returm 0;
}
