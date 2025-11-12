#include <bits/stdc++.h>
using namespace std;
const int N = 5010,P = 998244353;
int a[N];
int b[N];
int c[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans = 0;
	int flag = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i] != 1) flag = 1;
        c[i] = i;
	}
	sort(a+1,a+1+n);
	if(flag == 0){
        cout<<0;
        return 0;
	}
	int i = 3;
	while(i != n){
        if(c[i-2] == i){
            i++;
            for(int l = 1;l<=i;l++){
                c[l] = l;
            }
        }
        long long sum = 0;
        for(int j = 0;j<i;j++){
            sum+=a[c[i-j]];
        }
        if(sum > a[c[i]]*2) ans++;
        c[i]++;
        if(c[i] > n){
            int k = 1;
            c[i-1]++;
            while(true){
                if(c[i-k]+k <= n) break;
                else{
                    k++;
                    c[i-k]+=1;
                    for(int j = i-k+1;j<=i;j++){
                        c[j] = c[j-1] + 1;
                    }
                    if(k == n) break;
                }
            }
            c[i] = c[i-1] + 1;
        }
	}
	cout<<ans % P;
	return 0;
}
