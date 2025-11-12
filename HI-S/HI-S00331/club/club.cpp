#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	while(t){
		cin>>n;
		int ans=0;
		int num=n/2;
		for(int i=0;i<n*3;i++){
			cin>>a[i];	
		} 
		sort(a,a+n*3+1);
		for(int i=n*3;i>n*3-num;i--){
			ans+=a[i];
		}
		cout<<ans;
		t--;
	}
	return 0;
} 
