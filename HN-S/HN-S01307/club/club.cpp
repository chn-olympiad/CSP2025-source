#include<bits/stdc++.h>
using namespace std;
struct node{
	int a1,a2,a3;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int ans[t];
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		node a[n];
		for(int j=0;j<n;j++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a,a+n);
		for(int j=n;j>n/2;j--){
			ans[t]+=a[j].a1;
		}
		sort(a,a+n);
		for(int j=n;j>n/2;j--){
			ans[t]+=a[j].a2;
		}
		sort(a,a+n);
		for(int j=n;j>n/2;j--){
			ans[t]+=a[j].a3;
		}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
