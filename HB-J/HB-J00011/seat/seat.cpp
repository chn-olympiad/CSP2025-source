#include <bits/stdc++.h>
using namespace std;
int sort2(int a,int b){
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int num = n*m;
    int arr[num];
    for (int i = 0;i <= num;i++){
        cin >> arr[i];
    }

    int little_R = arr[0];
    sort(arr,arr+num,sort2);
    
    int paiming = 0;
    for (int i = 0;i < num;i++){
        if (arr[i] == little_R){
            paiming = i+1;
        }
    }
    int seat[n][m];
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            seat[i][j] = arr[i];
        }
        cout << i << " ";
    }
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            cout << seat[i][j] << " ";
        }
        cout << endl;
    }
    
    fclose(stdin);
    fclose(stdout);
}