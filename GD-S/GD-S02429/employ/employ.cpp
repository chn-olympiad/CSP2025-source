#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mo=998244353;
int num[N];
char li[N];
long long jc(long long a){
	long long ans=1;
	while(a){
		ans*=a;
		ans%=mo;
		a--;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>li[N];
	}
	for(int i = 1;i<=n;i++){
		cin>>num[i];
	}
	long long ans=0;
	for(int i = m;i<=n;i++){
		ans+=jc(i);
		ans%=mo;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
