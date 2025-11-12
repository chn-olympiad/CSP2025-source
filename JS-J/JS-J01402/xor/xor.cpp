#include <bits/stdc++.h>
using namespace std;

int a[500001];
int mem[500001][500001];
struct cp{
    int l,r;
};
bool cmp(cp a,cp b){
    return a.l<b.l?1:a.r-a.l<b.r-b.l;
}
vector<cp> p;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    bool f1=1;
    for (int i=0;i<n;i++){
        cin >> a[i];
        if (a[i]!=1) f1=0;
    }
    if (f1&&k==0){
        cout n/2;
    }
    if (f1&&k==1){
        cout n/3;
    }
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            mem[i][j]=j!=i+1?mem[i][j-1]^a[j]:a[i]^a[j];
            if (mem[i][j] == k){
                cp xxx;
                xxx.l = i;
                xxx.r = j;
                p.push_back(xxx);
            }
        }
    }
    sort(p.begin(),p.end(),cmp);
    cout << p.size();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
