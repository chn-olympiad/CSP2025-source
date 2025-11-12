#include<bits/stdc++.h>
using namespace std;
int n,m,arr[100],me,me_id;
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    cin >> me;
    arr[1]=me;
    for(int i=2;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+(n*m)+1,cmp);
    int j=1;
    while(j<=n*m){
        if(arr[j]==me){
            me_id=j;
            break;
        }
        j++;
    }
    if(((me_id-1)/n)%2==0){
        cout << (n+1)-(((me_id-1)/n)+1);
    }else{
        cout << ((me_id-1)/n)+1;
    }
    if(me_id%n==0){
        cout << n << ' ';
    }else{
        cout << me_id%n << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
