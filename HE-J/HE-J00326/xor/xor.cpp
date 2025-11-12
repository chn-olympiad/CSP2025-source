#include<bits/stdc++.h>
using namespace std;
int a[500050],l[500050],r[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,i,j,o,p=0;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			int sum=a[j];
			for(o=j-i;o<i;o++){
				sum=sum^a[o];
			}
			if(sum==k){
				ans++;
				l[p]=j-i+1;
				r[p]=j+1;
				p++;
			}
		}
	}
	cout<<ans;
	return 0;
}
