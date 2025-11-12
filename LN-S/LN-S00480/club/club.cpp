#include <bits/stdc++.h>
using namespace std;
struct three{
    int m,n,p;
}thr[10000];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,sum=0;
    cin >> t;
    for(int i=0;i < t;i++){
        cin >> n;
        for(int j=0;j < n;j++){
            cin >>thr[j].m>>thr[j].n>>thr[j].p;
            if(thr[j].m<thr[j].n){
                swap(thr[j].m,thr[j].n);
            }
        }
        for(int j=0;j < n;j++){
            sum+=thr[j].m;
        }
        cout<< sum<<endl;
        sum=0;
    }
    return 0;
}
