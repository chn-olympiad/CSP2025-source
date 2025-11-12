#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int k[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int kk=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]==0)kk++;
	}
	if(n-kk<m){
		cout<<0;
		cout<<endl;
		return 0;
	}
	int sum=1;
	for(int i=1;i<=n-kk;i++){
		sum*=i;
	}
	cout<<sum;
	return 0;
}
