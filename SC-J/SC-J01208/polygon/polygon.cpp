#include<iostream>
using namespace std;
int i,j,n;
unsigned long long ans=0,cnt=0;
void solve(int a,unsigned long long b[],int start,unsigned long long max){
	if(a==0)return;
	for(int k=start;k<n;k++){
		if(max<b[k])max=b[k];
		cnt+=b[k];
		if(cnt>max*2&&a>=2)ans++;
		solve(a-1,b,k+1,max);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	unsigned long long l[n];
	for(i=0;i<n;i++)cin>>l[i];
	for(j=0;j<n;j++){
		solve(j,l,j,0);
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}