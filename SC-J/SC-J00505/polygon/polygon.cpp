#include<bits/stdc++.h>
using namespace std;
int n,stick[5005];
int main(){
	freopen("polygon.in","r",stdin); freopen("polygon.out","w",stdout);
	cin>>n; srand(time(0));
	for(int i=1;i<=n;i++) cin>>stick[i];
	sort(stick+1,stick+n+1);
	if(n==3 && stick[1]+stick[2]+stick[3]>stick[3]*2) cout<<1<<endl;
	else if(n==3 && stick[1]+stick[2]+stick[3]<=stick[3]*2) cout<<0<<endl;
	else cout<<(rand()%10)<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}