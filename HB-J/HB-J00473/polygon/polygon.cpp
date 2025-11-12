#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
bool c[100][200000];
long long n,ans(0),p(998244353);
bool f(int p[],int q[]){
    for (int i=1;i<=n;i++)
        if (p[i]!=q[i]) return true;
    return false;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i],b[i] = a[i];
    sort(a+1,a+1+n);
    for (int i=1;;i++){
        if (i!=1 && !f(a,b)) break;
        for (int j=3;j<=n;j++){
            for (int k=1;k+j-1<=n;k++){
                int sum = 0,sum2 = 0,maxn = 0; 
                for (int w=k;w-k+1<=j;w++){
                    sum+=a[w];
                    sum2+=w;
                    maxn = max(maxn,a[w]);
                }
                if (sum>2*maxn && !c[j][sum*maxn]){
                    ans++;
                    c[j][sum*maxn]=true;
                    cout << maxn << " " << sum << endl;
                } 
            }
        }
        next_permutation(a+1,a+1+n);
    }
    cout << endl << endl;
    cout << ans%p;
    return 0;
}