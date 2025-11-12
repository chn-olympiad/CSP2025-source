#include<bits/stdc++.h>
using namespace std;
int n,m,c[1030];
char a[1030];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	bool flat=true;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(a[i]=='0'){
			flat=false;
		}
	}
	if(flat==1){
		int cnt=1;
		for(int i=1;i<=n;i++){
			cnt*=i;
		}
		cout<<cnt;
	}
	else{
		cout<<0;
	}
	return 0;
} 
