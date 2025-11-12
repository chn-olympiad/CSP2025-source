#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i],q=0,y;
		int c=a[i]^0;
		if(c==k){
			sum++;
			cout<<i<<endl;
		}else{
			for(int j=i+1;j<=n;j++){
				int m=x^a[j];
				if(m==k){
					sum++;
					q=-1;
					y=j;
					cout<<i<<" "<<j<<endl;
					break;
				}else{
					x=x^a[j];
				}
			}
			if(q==-1){
				i=y;
			}
		}
	}
	cout<<sum;
	return 0;
}
