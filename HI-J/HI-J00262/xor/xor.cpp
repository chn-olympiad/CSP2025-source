#include <bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==0){
		if(a[0]==0)sum++;
		for(int i=1;i<n;i++){
			if(a[i]==0||a[i]==a[i-1]&&a[i]==1){
				sum++;
				a[i]=0;
			}
		}
	}
	else{
		if(a[0]==1)sum++;
		for(int i=1;i<n;i++){
			if(a[i]==1||a[i]==a[i-1]&&a[i]==0){
				sum++;
				a[i]=1;
			}
		}
	}
	cout<<sum;
	return 0;
}


