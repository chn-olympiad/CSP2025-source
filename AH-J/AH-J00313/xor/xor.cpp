#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,k,a[10005],ans=0;
	cin>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int c=a[1];
	for(int i=2;i<=m;i++){
		if(c==0&&a[i]==1){
			if(k==1){
				ans++;i++;
				c=a[i];
			}
			else c=1;
		}
		else if(c==1&&a[i]==0){
			if(k==1){
				ans++;i++;
				c=a[i];
			}
			else c=1;
		}
		else {
			if(k==0){
				ans++;i++;
				c=a[i];
			}
			else c=0;
		}
	}
	cout<<ans;
	return 0;
}
