#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ans = 0;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];		
	}
	ans = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++){
		if(ans==a[i]){
			ans = i;
			break;
		}
	}
	int l = 0;
	if(ans%n==0){
		l = ans/n;
	}
	else{
		l = ans/n+1;
	}
	if(l%2==1){
		if(ans%n==0){
			cout<<l<<" "<<n;
		}
		else{
			cout<<l<<" "<<ans%n;
		}
	}
	else{
		if(ans%n==0){
			cout<<l<<" "<<1;
		}
		else{
			cout<<l<<" "<<n-(ans%n)+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
