#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int main(){
	int a[n];
	char b[3]={'1','2','3'};
	int ans=0;
	cin>>t;
	cin>>n;
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	for(int i=1;i<=t;i++){
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>=a[i] && b[3]<=n/2){
				ans+=max(a[i],ans);
			}
		}
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
