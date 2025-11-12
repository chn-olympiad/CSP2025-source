#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, max = -1,maxn,maxm,sum = 0;
    freopen("seat.out",'w',"stdout");
    freopen("seat.in",'r',"stdin");
    cin >>n>>m;
    int a[n][m];
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < m;j ++){
            cin>>a[i][j];
        }
    }
    for(int z = 0;z < n*m;z ++){
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                if(max < a[i][j]) {
                    max = n;
                    maxn = i;
                    maxm = j;
                    
                }

            }
        }
        if(maxn == 0 && maxm == 0) break;
        a[maxn][maxm] = -100,sum ++;
    }
    cout<<(sum/n);
    if((sum/n)%2 == 0)
        cout<<' '<<sum%n;
   else if((sum/n)%2 == 1)
        cout<<' '<<(sum%n)+n-1;
    return 0;
}