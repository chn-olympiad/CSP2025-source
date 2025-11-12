#include<iostream>
using namespace std;
long long n,k,a[500010],q[500010],l=1,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1)q[i]=q[i-1]^a[i];
		else q[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(l==1){
			if(q[i]==k){
				sum++;
				l=i;
				continue;
			}
		}
		for(int j=l;j<i;j++){
			if((q[i]^q[j])==k){
				sum++;
				l=i;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}
