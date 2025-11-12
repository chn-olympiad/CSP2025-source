#include<bits/stdc++.h>
using namespace std;
long long n,k,a[3000],s,t,f,p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=i;k<=j;k++){
				s+=a[k];
				t++;
			}
			p=s/t;
			if(p&k){
				f++;
			}
			s=0;
		}
	}
	cout<<f<<endl;
	return 0;
}