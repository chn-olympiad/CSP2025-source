#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		//cout<<a[i]<<" ";
		if(a[i]==r){
			int s=(n*m-i+1);
			//cout<<s<<endl;
			if(((s-1)/n)%2==0){
				cout<<(s-1)/n+1<<" ";
				if(s%n==0) cout<<n;
				else cout<<s%n;
			}
			else{
				cout<<(s-1)/n+1<<" ";
				cout<<n-s%n+1;
			} 
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

