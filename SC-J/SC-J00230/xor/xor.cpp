#include<bits/stdc++.h>
using namespace std;

long long n, k, a[114514], ans, temp;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int i=1, j=2;
	while(i<=n){
		if(a[i]==k) ans++, i++;
		else{
			temp=a[i], j=i;
			while(1){
				temp=temp^a[++j];
				if(j>n){
					i++;
					break;
				}
				if(temp==k){
					ans++, i=j+1;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}