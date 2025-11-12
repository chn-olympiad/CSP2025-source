#include <bits/stdc++.h>
using namespace std;
int n;
int r[5010];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	sort(r,r+n,cmp);
	int ans=0;
	for(int i=0;i<n;i++){
		int sum=i+r[i+1];	
		for(int j=i;j<n;j++){
			sum+=r[i];
			if(sum>r[j]/2){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
