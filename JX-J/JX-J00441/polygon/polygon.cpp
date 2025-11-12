#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,wg[5005];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>wg[i];
		}
	sort(wg+1,wg+n+1);
	if(n==3){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt=cnt+wg[i];
			}
		if(cnt>wg[n]*2){
			cout<<1;
			}
		else{
			cout<<0;
			}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
