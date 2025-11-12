#include<bits/stdc++.h>
using namespace std;

int a[10010][3] = {0};
int s = 0;
int flag[10010][3];

int main(){
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n, b[3]={};
        cin>>n;
        int li = n/2, maxi = -1, s = 0;
        for(int i = 1; i<=n; i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
        for(int i = 1; i<=n; i++) {flag[i][0] = a[i][0]; flag[i][1] = a[i][1]; flag[i][2] = a[i][2];};
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n-1; j++){
                if(a[j][0]+a[j][1]+a[j][2] > a[j+1][0]+a[j+1][1]+a[j+1][2]) {
                    swap(a[j][0], a[j+1][0]);
                    swap(a[j][1], a[j+1][1]);
                    swap(a[j][2], a[j+1][2]);
                };
            };
        };
        int sele[3] = {};
        for(int j = 1; j<=n; j++) {
            // printf("s = %d\n", s);
            int will = max(sele[0]<li? a[j][0]:0, max(sele[1]<li? a[j][1]:0, sele[2]<li? a[j][2]:0));
            s += will;
            //printf("will = %d and a[%d][2] = %d ", will, j ,a[j][2]);
            if(will == a[j][0]) sele[0]++;
            else if (will == a[j][1]) sele[1]++;
            else if (will == a[j][2]) sele[2]++;

        };
        cout<<s<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
