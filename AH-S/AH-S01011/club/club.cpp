#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdio>
using namespace std;
int t,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int l=1;l<=t;l++){
        cin>>n;
        int sum=0,a[100005],b,c;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b>>c;
        }
        sort(a+1,a+1+n);
        for(int i=n;i>n/2;i--){
            sum+=a[i];
        }
        cout<<sum<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
3

4
4 2 1
3 2 4
5 3 4
3 5 1

4
1 2 3
3 1 2
1 3 2
2 1 3

4
3 4 2
1 3 3
2 2 1
4 1 4


4
0 1 0
0 1 0
0 2 0
0 2 0

4
2 1 3
2 1 3
2 1 3
2 1 3

4
1 3 1
2 4 2
3 1 3
4 2 4


2
10 9 8
4 0 0

2
1 2 3
1 2 3
*/
/*
dp[i][j]:前i个元素中选j个能取得的最大值
dp[i][j]=dp[i-1][j]
        =dp[i-1][j-1]+a[i]
         p[i]--;

f[i][j]:前i个元素中选j个(容量为j),（每个最少选1个最多选n/2），能取得的最大值

*/
