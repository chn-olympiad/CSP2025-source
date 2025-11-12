#include<bits/stdc++.h>
using namespace std;
int good[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		long long sum=0;
		cin>>n;
		for(int j=0;j<n;j++){
			int maxa=-1;
			for(int k=0;k<3;k++){
				cin>>good[j][k];
				maxa=max(good[j][k],maxa);
			}
			sum+=maxa;
		}
		cout<<sum<<endl;
	}
	return 0;
}
