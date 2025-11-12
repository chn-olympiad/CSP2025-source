#include<bits/stdc++.h>
using namespace std;
struct people{
    int mark;
    int id;
};
bool cmp(people a,people b){
    return a.mark < b.mark;
}
int main(){
    freopen("seat1.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    people a[100] = {0};
    for(int i = 0;i <= n*m-1;i++){
        cin >> a[i].mark;
        a[i].id = i+1;
    }

    sort(a,a+n*m,cmp);

    int seat[10][10];
    int xiabiao = 0;
    for(int i = 0;i <= m-1;i++){
        if (i%2 == 1){
            for(int j = 0;j <= n-1;j++){
                if(a[xiabiao].id == 1){
                    cout << i << endl << j;
                    break;
                }
                seat[i][j] = a[xiabiao].id;
                xiabiao++;
            }
        }else{
            for(int j = n-1;j >= 0;j--){
                if(a[xiabiao].id == 1){
                    cout << i << endl << j;
                    break;
                }
                seat[i][j] = a[xiabiao].id;
                xiabiao++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
