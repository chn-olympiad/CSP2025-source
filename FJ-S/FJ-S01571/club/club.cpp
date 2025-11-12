#include<bits/stdc++.h>
using namespace std;
long long t,n,a,c[10001];
long long s=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a;
			c[i]=a;
			cin>>a>>a;
		}
		sort(c+1,c+1+n);
		for(int i=n;i>n/2;i--){
			s+=c[i];
		}
		cout<<s<<endl;
	}
	
	return 0;
} 
