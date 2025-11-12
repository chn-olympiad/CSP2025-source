#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],s=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		long long m=a[i],mx=a[i];
		for(int j=i+1;j<n;j++){
			m=a[j]+m;
			mx=max(a[j],mx);
			if(j-i>=2&&2*mx<m){
				s++;
				s=s%998244353;
				break;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
