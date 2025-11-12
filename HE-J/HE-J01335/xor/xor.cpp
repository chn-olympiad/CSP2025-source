#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if( k == 0 ){
		for(int i=1;i<=n;i++){
			if( a[i] == k )  ans++;
			else if( a[i] == a[i-1] ){
				ans++;
				i++;
			}
		}
	}
	if( k == 1 ){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=20;j++){
				if( a[i] == pow(2,j) ){
					for(int k=i;k<=n;k++){
						if( a[k] == a[i]+1 ){
							ans++;
							i++;
							a[k] = -1;
							//cout << ans << "l" << endl;
							break;
						}
					}
				}
			}
			if( a[i] == 1 ){
				ans++;
				//cout << ans  <<  endl;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
