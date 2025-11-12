#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100005];
int t[1000009];
long long num,sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		t[i]++;
	}
	for(int i=1;i<=n;i++){
		if(t[i]!=0){
			for(int j=1;j<=t[i];j++){
				num=num*i;
				num%998244353;
			}
			sum=num%998244353;
		}
	}
	cout<<sum;
	return 0;
}
