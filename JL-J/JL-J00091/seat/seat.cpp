#include<bits/stdc++.h>
using namespace std;
struct Node{
    int num, grade;
};
bool cmp(Node a, Node b){
    return a.grade > b.grade;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    std::cin >> n >> m;
    int a[n][m]; //n hang m lie
    Node cad[n * m];
    for(int i = 1; i <= n * m; i ++){
        int g;
        std::cin >> g;
        cad[i-1].num = i;
        cad[i-1].grade = g;
    }
    std::sort(cad, cad + n*m, cmp);
    int filled = 0;
    int hang = 0, lie = 0;
    while(filled != n*m){
        a[hang][lie] = cad[filled].num;
        if(lie % 2 == 0){
            if(hang != n-1) hang ++;
            else lie ++;
        }else{
            if(hang != 0) hang --;
            else lie ++;
        }
        filled ++;
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(a[i][j] == 1){
                std::cout << j+1 << " " << i+1;
                break;
            }
        }
    }
    return 0;
}
