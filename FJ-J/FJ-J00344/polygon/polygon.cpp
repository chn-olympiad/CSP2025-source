#include <bits/stdc++.h>
using namespace std;
int n,a[1000000],cnt=0,x=1,y=2,sum=0,t,b,c,d;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	while(x<=n-2){
		for(int i=y;i<=n-1;i++){
			for(int j=y+1;j<=n;j++){
				b = a[x];
				c = a[i];
				d = a[j];
				ans = max(max(b,c),d);
				sum = a[x] + a[i] + a[j];
				if(sum > 2*ans){
					cnt++;
				}
			}
		}	
	}
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}