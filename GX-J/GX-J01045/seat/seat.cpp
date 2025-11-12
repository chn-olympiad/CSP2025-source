#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat3.in", "r", stdin);
    freopen("seat2.out", "w", stdout);
    int n, m;
    cin>> n >> m;
    int seat [10] [10] ={0};
    int q=0;
    int mc [101] ={0};
    int js=0;
    for(int i =0; i<n; i++){
        for(int j =m-1; j>=0; j--){
            cin>> seat [i][j];
            mc[js] = seat[i][j];
            js++;
        }
    }
    q = seat[0][0];
    for(int i = 0; i<101; i++){
        for(int j = i; j<n; j++){
            if(mc[i] < mc[j]){
                swap(mc[i], mc[j]);
            }
        }
    }
    js = 0;
    for(int i = 0; i<n; i++){
        if(i%2==0){
            for(int j =0; j<m; j++){
                seat[j][i] = mc[js];
                js++;
            }
        }else{
            for(int j =m-1; j>=0; j--){
                seat[j][i] = mc[js];
                js++;
            }
        }
    }
    for(int i =0; i<n; i++){
        for(int j =m-1; j>=0; j--){
            if(q == seat[i][j]){
                    int a = ++i;
                    int b = ++j;
                    cout<< b+1 <<" "<< a+1;
                    return 0;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
