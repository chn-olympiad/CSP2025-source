#include<bits/stdc++.h>

using namespace std;

int n,k;
int a[500020];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			s++;
		}
	}
	int d=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0&& a[i+1]==0){
			d++;
			i++;
		}
	}
	if(k==0){
		cout<<s/2+d;
		return 0;
	}else {
		cout<<min(s,n-s);
	}
	return 0;
}
