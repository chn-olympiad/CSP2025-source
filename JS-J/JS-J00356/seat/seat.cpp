#include <bits/stdc++.h>
using namespace std;
int score[105]={},m,n,k;
int main(){
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    cin >> n >> m;
    for(int i=0;i<n*m;i++){
        cin >> score[i];
    }
    k=score[0];
    sort(score,score+m*n);
    int h;
    for(int i=0;i<m*n;i++){
        if(score[i]==k)h=n*m-i;
    }
    int x=(h-1)/n+1;
    h-=(x-1)*n;
    cout << x;
    if(x%2){
        cout << ' ' << h;
    }
    else{
        cout << ' ' << m-h+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
