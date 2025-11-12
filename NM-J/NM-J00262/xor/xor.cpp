#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=0,k=0,yh=2;
	scanf("%d%d",&n,&k);
	vector<int>a(n);
	string s;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]==k){
			yh=1;
		}
		
	}
	cout<<yh;
	return 0;
}
