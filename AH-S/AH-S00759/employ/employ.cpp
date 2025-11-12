#include <bits/stdc++.h>
using namespace std;
int n, m, c[505], k, num[505], mol=998244353;
char s[505];
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    k=n;
    scanf("%s", s+1);
    for(int i=1; i<=n; i++){
	    scanf("%d", &c[i]);
	    if(s[i]=='0'){
	        k--;
	        num[i]=num[i-1]+1;
		}
		else{
			num[i]=num[i-1];
		}
	}
	sort(c+1, c+n+1);
	if(k<m)
	    printf("0\n");
	else{
		int ans=1;
		if(m==n){
			for(int i=1; i<=m; i++){
				ans=(ans*i)%mol;
				ans%=mol;
			}
		}
		else{
			if(m==1){
				for(int k=1; k<n; k++){
			        ans=ans*k%mol;
                    ans%=mol;
				}
				for(int i=1; i<=n; i++){
				    if(s[i]=='1'){
						for(int j=1; j<=n; j++){
							if(c[j]>i){
							    ans=(ans*(n-j+1))%mol;
				                ans%=mol;
							    break;
						    }
						}
						break;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
