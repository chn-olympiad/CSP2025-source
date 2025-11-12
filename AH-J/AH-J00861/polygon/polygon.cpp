#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}for(int i=1;i<(1<<n);i++){
		int c=0,s=0,max=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				c++;s+=a[j];
				if(a[j]>max) max=a[j];
			}
		}if(c>=3 && s>2*max) cnt++;
		cnt%=998244353;
	}cout<<cnt;
	return 0;
}
