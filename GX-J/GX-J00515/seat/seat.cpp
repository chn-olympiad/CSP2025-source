#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat .out","w",stdout);

    int n,m;
    cin >> n >> m;
    vector <int> a;
    int j;
    for(int i=0; i<n*m; i++){
        cin >> j;
        a.push_back(j);
    }
    int r = a[0];
    int f;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    for(int i=0; i<n*m; i++){
        if(a[i] == r){
            f = i+1;
        }
    }
    int seat[2] ={0};
    seat[0] = f/n;
    if(f%n != 0){
        seat[0]++;
        if(seat[0]%2 != 0){
            seat[1] = f%n;
        }else{
            seat[1] = n-f%n+1;
        }
    }else{
        if(seat[0]%2 != 0){
            seat[1] = n;
        }else{
            seat[1] = 1;
        }
    }
    cout << seat[0] << " " << seat[1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
