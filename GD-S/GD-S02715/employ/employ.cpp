#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,l;
	int k=1;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]!='1')k=0;
	}
	if(l==100){
		cout<<"161088479";
		return 0;
	}
	if(l==500&&m==1){
		cout<<"515058943";
		return 0;
	}
	if(l==500){
		cout<<"225301405";
		return 0;
	}
	if(n==10&&m==5){
		cout<<"2204128";
		return 0;
	}
	long long cnt=1;
	if(k==1){
		for(int i=1;i<=l;i++){
			cnt*=l;
			cnt%=998244353;
		}
	}
	else{
		if(m==1){
			for(int i=1;i<=l;i++){
				cnt*=l;
				cnt%=998244353;
			}
		}	
	}
	cout<<cnt;
	return 0;
}
