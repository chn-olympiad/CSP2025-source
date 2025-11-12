#include <bits/stdc++.h>
using namespace std;
long long n[15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[n+5][m+5];
	int s[n*m+5];
	for(int i = 1;i<=n*m;i++){
        cin>>s[i];
	}
	int a = s[1];
	sort(s+1,s+1+n*m);
    int i = 1,j = 1;
    int flag = 0;
	for(int k = m*n;k>=1;k--){
        c[j][i] = s[k];
        if(s[k] == a){
            cout<<i<<' '<<j<<endl;
            return 0;
        }
        if(flag == 0){
            j++;
        }
        if(flag == 1){
            j--;
        }
        if(j > n){
            flag = 1;
            j--;
            i++;
        }
        if(j == 0){
            flag = 0;
            j++;
            i++;
        }
	}
	return 0;
}
