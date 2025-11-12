#include<iostream>
using namespace std;
const int N=998244353;
int s[502],c[502],ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,mm;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==1){
			mm++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		
	}
	if(m>mm){
		cout<<0;
	}
	ans=1;
	for(int i=1;1<=mm;i++){
		ans*=2;
	}
	cout<<ans%N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
