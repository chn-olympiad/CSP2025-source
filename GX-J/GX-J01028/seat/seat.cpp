#include <bits/stdc++.h>
using std::cout;
using std::cin;
int main(){
    int n,m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int score[n*m];
    for(int i =0;i<n*m;i++){
        cin>>score[i];
    }
    int hang=1,lie=1;
    for(int i=0;i<n*m;i++){
        if(score[i]>score[0]){
            hang++;
            if(hang>n){
                lie++;
                hang=1;
            }
        }
    }
    if(lie%2==0)hang=n+1-hang;
    cout<<lie<<" "<<hang;
    return 0;
}
