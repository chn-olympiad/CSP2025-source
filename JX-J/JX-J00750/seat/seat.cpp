#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],num,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==num){
			ans+=1;
			int x=ans/n;
			int y=ans%n;
			if(y!=0) x++;
			if(x%2==0){
				cout<<x<<" "<<n-y+1;
			}
			else{
				if(y==0) cout<<x<<" "<<n;
				else cout<<x<<" "<<y;
			}
		}
		ans++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
