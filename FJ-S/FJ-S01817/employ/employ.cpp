#include<bits/stdc++.h>
using namespace std;
long long ppow(int n){
	if(n==1)return 1;
	return ppow(n-1)*n%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int m,n,sum=0;
	cin>>m>>n;
	sum = m;
	string a;
	cin>>a;
	bool flag = true;
	for(int i = 0;i < a.length();i ++){
		if(a[i] == '0'){
			flag = false;
		}
	}
	int num[m+10];
	for(int i = 1;i <= m;i ++){
		cin>>num[i];
		if(num[i]==0)sum --;
	}if(sum < n or flag == false){
		cout<<0;
	}else{
		if(sum!=m)cout<<ppow(sum)*ppow(m-sum)%998244353;
		else cout<<ppow(sum)%998244353;
	}
	return 0;
} 
