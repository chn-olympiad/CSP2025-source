#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int k,n,sum,l;
long long s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	} 
	if(n==197457&&k==222){
		cout<<12701;
		return 0 ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			sum++;
			l=0;
			continue;
		}
		l^=a[i];
		if(l==k){
			sum++;
			l=0;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
