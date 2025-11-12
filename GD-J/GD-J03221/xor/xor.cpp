#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;long long k;
	cin>>n>>k;
	int op=1,op1=1;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)	op=0;
		if(a[i]>1) op1=0;
	}
	if(op==1){
		if(k==0){
			cout<<n/2<<endl;
			return 0;
		}
		else if(k==1){
			cout<<n<<endl;
			return 0;
		}
	}
	if(op1==1){
		if(k<=1){
			if(k==0){
				int count=0,e=1;
				while(e<n){
					if(a[e]==1&&a[e+1]==1){
						count++,e++;
					}
					e++;
				}
				for (int w=1;w<=n;w++){
					if(a[w]==0){
						count++;
					}
				}
				cout<<count<<endl;
				return 0;
			}
			else if(k==1){
				int count=0;
				for (int w=1;w<=n;w++){
					if(a[w]==1){
						count++;
					}
				}
				cout<<count<<endl;
				return 0;
			}
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}
