#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long int n,m,pan=0,sum=0;
	long long int s[100001],c[100001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		sum++;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			pan=1;
		}
	}
	if(pan==1){
		cout<<sum;
	}
	//wo yao shang 2 deng awa
	return 0;
}
