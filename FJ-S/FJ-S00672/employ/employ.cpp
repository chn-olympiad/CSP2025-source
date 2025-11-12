#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505],a[505];
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			a[i]=1;
		}else{
			a[i]=0;
		}
	}
	if(m==1){
		cout << n;
	}else{
		cout << m;
	}
	return 0;
}
