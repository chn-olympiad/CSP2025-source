#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500010];

bool f(int l,int r){
	int sum = 0;
	for(int i=l;i<=r;++i){
		sum^=a[i];
	}
	return (sum == k);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n>> k;
	
	for(int i=0;i<n;++i) cin >> a[i];
	
	int i=0;
	int ans = 0;
	while(i<n){
		bool flag = false;
		for(int j=i;j<n;++j){
			if(f(i,j)) {ans++;i=j+1;flag = true;break;}
		}
		if(flag == false) i++;
	}

	cout<<ans;
	return 0;
}
