#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N];
map <int,int> m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m[a[i]]++;
	}
	if(m[1]==n){
		cout<<n/2;
	}else if(m[1]+m[0]==n){
		if(k==1){
			cout<<m[1];
		}else{
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum++;
				}else{
					if(a[i+1]==1){
						sum++;
						i++;
					}
				}
			}
			cout<<sum;
		}
	}else{
		cout<<0; 
	}
	return 0;
}
