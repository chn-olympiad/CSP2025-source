#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,a[N],ans,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1,j=1;
	int sum=0;
	for(i;i<=n;){
		bool flag=0;
		for(j=i;j<=n;j++){
			sum=a[i];
			for(int f=i+1;f<=j;f++){
				sum^=a[f];
			}
			if(sum==k){
				ans++;
				flag=1;
				break;
			}
		}
		if(flag==1)
		i=j+1;
		else
		i++;
	}
	cout<<ans;
	return 0;
}
