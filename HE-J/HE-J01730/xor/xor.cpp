#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int n,m;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			ans++;
		}
	}
	if(m>=2){
		cout<<0;
	}
	else if(m==1){
		cout<<ans;
	}
	else{
		int l = 0,p = 1;
		l+=(n-ans);
		while(p<n){
			if(a[p]==1 && a[p+1]==1){
				l++;
				p+=2;
			}
			else{
				p++;
			}
		}
		cout<<l;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
