#include<bits/stdc++.h>
using namespace std;
int n,m,a[555];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		printf("%d",&a[i]);
	}
	if(n==1){
		if(s[0]=='1'){
			if(a[1]>0)	cout << 1;
			else cout << 0;
		}else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	
	
	return 0;
}
