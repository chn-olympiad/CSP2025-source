#include<bits/stdc++.h>
using namespace std;
const int MOD=998224353;
int n,m,a[505],t,f[505],ans,x,y;
char k[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			t++;
		}
	}
	x=1;
	if(n<m+t){
		cout<<0;
	}
	else{
		for(int i=1;i<=n-t;i--)
		{
			x=(x*i)%MOD;
		}
		
		cout<<x;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
