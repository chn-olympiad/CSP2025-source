#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
ifstream fin("seat.in");
ofstream fout("seat.out");
int n,m,a[MAXN],x;
int main(){
    fin>>n>>m;
    for(int i=1;i<=n*m;i++)fin>>a[i];
    x=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        int j=n*m-i+1;
        if(a[j]==x){
            int y=i%(2*n);
            if(y<=n&&y!=0)fout<<(i+n-1)/n<<" "<<y;
            else fout<<(i+n-1)/n<<" "<<(2*n-y+1)%(2*n);
        }
    }
}
