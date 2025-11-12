#include <iostream>
using namespace std;
const int N=1000000+10;
int n;
long long k;
long long a[N],s[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool XA=true;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1){
			XA=false;
		}
	}
	if(k!=0){
		XA=false;
	}
	if(XA){
		cout<<n/2;
		return 0;
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]^a[i];
	}
	
	long long ans=0;
	for(int i=1;i<=n;){
		int index=i;
		if(i==1){
			while(index<=n&&s[index]!=k){
				index++;
			}
			if(index<=n&&s[index]==k){
				ans++;
				i=index+1;
			}else{
				i++;
			}
		}else{
			while(index<=n&&(s[index]^s[i-1])!=k){
				index++;
			}
			if(index<=n&&(s[index]^s[i-1])==k){
				ans++;
				i=index+1;
			}else{
				i++;
			}
		}
	}
	
	cout<<ans;
	return 0;
}