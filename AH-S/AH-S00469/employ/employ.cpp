#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,a[1005],f=1;
long long h=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	getline(cin,s);
	for(int i=0;i<int(s.size());i++){
		if(s[i]!='1'){
			f=0;
			break;
		}
	}
	int cnt3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt3++;
		}
	}
	if(n-cnt3<m){
		cout<<0;
		return 0;
	}
	if(f==1){
		for(int i=n-cnt3;i>=n-cnt3-m-2;i--){
			h=(h*i)%998244353;
			cout<<h<<endl;
		}
		
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

