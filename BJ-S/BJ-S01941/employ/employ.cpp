#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r","stdin");
	freopen("employ.out","w","stdout");
	long long n,m,nai[1001],shu=0,sha=0,first=99999999,li=0,len1;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>nai[i];
		if(nai==0) sha++;
	}
	len1=s.size();
	for(int i=0;i<=len1-1;i++){
		if(s[i]==1){
			shu++;
			first=min(first,i+1);
		} else li++;
	}
	if(m==1){
		long long sum1=0,sum2=1;
		for(int i=1;i<=n;i++){
			sum2=1;
			if(nai[i]>first) {
				for(int i=1;i<=n-1;i++){
					sum2=sum2*i%998244353;
				}
				sum1=(sum1+sum2)%998244353;
			}
		}
		cout<<sum1;
	}else if(m==n){
		if(li>0||sha>0) cout<<0;
		else {
			long long sum1=1;
			for(int i=1;i<=n;i++){
				sum1=sum1*i%998244353;
			}
			cout<<sum1;
		}
	}
	return 0;
}
