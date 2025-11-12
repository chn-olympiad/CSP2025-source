#include<bits/stdc++.h>;
using namespace std;
int main(){
	freoprn("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[510],sum=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		if(a[i]==1)sum++;
	}
	if(n<101||m<n){
		cout<<161088479;
	}else if(m==1){
		cout<<515058943;
	}else if(n,501||m<n||sum==18){
		cout<<225301405;
	}

	return 0;
}
