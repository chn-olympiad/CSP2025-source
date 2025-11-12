#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int a[1010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			cnt++;
		}
	}
	long long ans=1;
	if(cnt<m){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
