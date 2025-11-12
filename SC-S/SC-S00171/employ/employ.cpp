#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=1;
			cnt=i+1;
			break;
		}
	} 
	if(f==0) cnt=s.size();
//	cout<<cnt<<'\n';
	if(cnt>=m){
		long long k=1,kkk=1,kk=1;
		for(int i=2;i<=cnt;i++){
			k*=i;
			if(i==m) kk=k;
			if(i==cnt-m) kkk=k;
		}
	//	cout<<k<<' '<<kk<<' '<<kkk<<'\n';
		cout<<k/kk*kkk%998244353;
	}else cout<<0;
	return 0;
}