#include<bits/stdc++.h>
using namespace std;
string a,ans;
long long p=1;
long long n;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>a;
	for(long long i=0;i<=sizeof(a);i++){
		if(a[i]>='0'&&a[i]<='9'){
			ans[p]=a[i];
			p++;
		}
	}
	for(long long i=1;i<=p;i++){
		for(long long j=1;j<=p;j++){
		if((ans[j])<(ans[j+1])){
			n=ans[j];
			ans[j]=ans[j+1];
			ans[j+1]=n;
		}	
		}
	}
	for(int i=1;i<=p;i++){
		cout<<ans[i];
	} 
	return 0;
} 