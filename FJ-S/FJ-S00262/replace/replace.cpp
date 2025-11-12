#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000000];
int sum1=1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int sum=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]==1){
			sum++;
		}
	}
	for(int i=1;i<=n;i++){
		sum1=sum1*i%998244353;
	}
	cout<<sum1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
