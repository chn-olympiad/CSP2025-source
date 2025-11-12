#include<bits/stdc++.h>
using namespace std;
int n,m,s[505],c[505],num;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q;
		if(q=='1'){
			s[i]=1;
		}else{
			s[i]=0;
			num++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(num==n){
		cout<<0;
		return 0;
	}
	sort(c+1,c+1+n);
	for(int j=1;j<=m;j++){
		
	}
	return 0;
}
