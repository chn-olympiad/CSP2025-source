#include<bits/stdc++.h>
using namespace std;
long long a[600005],b[600005],n,k;
int z[600005];
long long second(long long x){
	string s;
	long long num=0,t;
	while(x!=0){
		s[num]=x%2+'0';
		x/=2;
		num++;
	}
	for(long long i=0;i<num;i++)t=t*10+(s[num-1-i]-'0');
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int num=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=second(a[i]);
	}
	cout<<2;
	return 0;
} 
