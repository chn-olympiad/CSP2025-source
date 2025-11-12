#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		int maxn=0;
		int tep=0;
		for(int i=1;i<=n;i++){
			tep+=a[i];
			if(a[i]>=maxn){
				maxn=a[i];
			}
		}
		if(tep>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n<3){
		cout<<0;
	}
	return 0;
}
