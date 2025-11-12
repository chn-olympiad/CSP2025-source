#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[20][20],l[200];
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i<n*m;i++){
        cin>>l[i];
    }
    int target = l[0];
    sort(l,l+n*m,cmp);
    int t = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            a[j][i] = l[t++];
        }
        i++;
        for(int j = n-1;j>=0;j--){
            a[j][i] = l[t++];
        }
    }
    int ansx,ansy;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j] == target){
                ansx = i;
                ansy = j;
            }
        }
    }
    cout<<ansy+1<<" "<<ansx+1;
    return 0;
}
