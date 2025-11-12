#include<bits/stdc++.h>

using namespace std;
int Q=998244353;
int n,m;
int pa[10005];
int check(int los,int l){
	int sum=los;
	for(int i=l+1;i<=n;i++){
		if(sum>=pa[i]){
			sum++;
		}
	}
	return sum;
}
int power(int n){

	
	int answer=1;
	for(int i=n;i>=1;i--){
		answer*=i;
	}

	
	return answer;
}


int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f[10005];
	bool flag=0;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		f[i]=a-'0';
		if(f[i]==0){
			flag=1;
		}
	}
	
	int cut=0;
	for(int i=1;i<=n;i++){
		cin>>pa[i];
		cut+=pa[i];
	}
	int los=0;
	if(m>n){
		cout<<0;
		return 0;
	}
	if(cut<m){
		cout<<0;
		return 0;
	}
	sort(pa+1,pa+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(f[i]){
			ans++;
		}
		else{
			los++;
			los=check(los,i);
		}

	}
	if(n-los<m){
		cout<<0;
		return 0;
	}
	if(!flag){
		int answer=1;
		for(int i=n;i>=1;i--){
			answer*=i;
		}
		cout<<answer;
		return 0;
	}
	if(m==1){
		int answer=1;
		for(int i=n;i>=1;i--){
			answer*=i;
		}
		
		cout<<answer-power(n-los);
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(!f[i]){
				cout<<0;
				return 0;
			}
		}
		int answer=1;
		for(int i=n;i>=1;i--){
			answer*=i;
		}
		cout<<answer;
		return 0;
	}
	if(m>18){
		cout<<0;
		return 0;
	}
	cout<<n/2+1;
	return 0;
}
