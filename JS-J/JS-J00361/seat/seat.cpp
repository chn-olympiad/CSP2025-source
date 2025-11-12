#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int x,p=1,len=n*m;
    bool a[101];
    memset(a,0,sizeof(a));
    cin >> x;
    for(int i =1;i<len;i++){
        int u;
        cin >> u;
        a[u]=1;
        if(u>x){
            ++p;
        }
    }

    int r,c;
    r = (p-1)/n +1;
    c = p-((r-1)*n);
    if(r%2==0){
        c= n-c+1;
    }
    cout << r  << " " << c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//waiting for Alan's saving
//praying for my wanting
//praying for scores
