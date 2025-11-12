#include<bits/stdc++.h>
using namespace std;
long long N=998244353;
int s[505];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	int flag=1;
	for(int i=0;i<n;i++){
		s[i+1]=a[i]-'0';
		if(s[i+1]==0){
			flag=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	int num=1;
	while(c[num]==0){
		num++;
	}
	int sum=n-num+1;
	long long ans=1;
	while(sum>=1){
		ans*=sum;
		ans%=N;
		sum--;
	}
	ans*=num;
	cout<<ans%N;
	return 0;
}
