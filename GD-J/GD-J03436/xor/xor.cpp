#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500],ans,zx=1,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//a[i]=a[i]xor(a[i-1]);
	}
	/*for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
	cout<<(a[1]xor(a[2]))<<" ";
	cout<<(a[1]xor(a[2])xor(a[3]))<<" ";
	cout<<(a[2]xor(a[3]))<<" ";
	cout<<((a[1])xor(a[2])xor(a[3])xor(a[4]));
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++) cout<<(a[i]xor(a[j]))<<" ";
	}*/
	for(int i=1;i<=n;i++){
		for(int j=zx;j<=i;j++){
			long long ans=a[j];
			for(int k=j+1;k<=i;k++) ans=(ans)xor(a[k]);
			if(ans==m){
				zx=i+1;
				sum++;
				break;
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
