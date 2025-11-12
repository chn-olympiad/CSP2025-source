#include <bits/stdc++.h>
using namespace std;
int a[100005];
int s=0,x=0,flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		s=s+a[i];
		if(s%k==0&&s!=0){
			x++;
			s=0;
		}
		if(a[i]==0&&k==0){
			x++;
		}

	}
	cout << x;
	return 0;
}
