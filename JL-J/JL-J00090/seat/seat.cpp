#include<bits/stdc++.h>
using namespace std;
int lists[1001];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n , m, person;
    cin >> n >> m;
    int input;
    for(int i = 1 ; i <= (n*m); i++){
        cin >> lists[i];
        if(i == 1) person = lists[i];
    }
    sort(lists+1,lists+m*n+1,cmp);
    int its = 1;
    for(int i = 1 ; i <= m ; i++){
        if( i % 2 == 1){
            for(int j = 1 ; j <= n ; j++){
                if(lists[its] == person){
                    cout << i << " " << j;
                    return 0;
                }
                its++;
            }
        }else{
            for(int j = n ; j >= 1 ; j--){
                if(lists[its] == person){
                    cout << i << " " << j;
                    return 0;
                }
                its++;
            }
        }
    }
    return 0;
}
