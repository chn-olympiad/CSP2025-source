#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,k,a[N],q=0,w=0;
long long sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			q++;
		}
		if(a[i]==1){
			w++;
		}
	}
	if(k==0){
		cout<<q;
		return 0;
	}
	if(k==1){
		cout<<w;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int t=a[i];
		if(t==k){
			sum++;
		}else{
			for(int j=i+1;j<=n;j++){
				t^=a[j];
				if(t==k){
					sum++;
					i=j;	
					break;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
