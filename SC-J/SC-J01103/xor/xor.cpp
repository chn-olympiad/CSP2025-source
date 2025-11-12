#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],ans=0,p=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(k==0)
		for(int i=0;i<n;i++){
			if(a[i]==0){
				ans++;
				ans+=(p%2);
				p=0;
			}
			else
				p++;
		}
	else{
		for(int j=1;j<n;j++)
			for(int i=1;i<n;i++){
				if(a[i-1]!=a[i]&&a[i-1]>0&&a[i]<2){
					ans++;
					a[i]=-1;
				}
				else{
					a[i-1]=0;
					n--;
					for(int p=i;p<n;p++)
						a[p]=a[p+1];
				}
			}
	}
	cout<<ans;
	return 0;
}