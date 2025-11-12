#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	int n,k,a[500000],q=1,p=1,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!>q&&i!<p||i!<q&&i!>p){
				ans++;
			}
		}
		q++,p++;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
