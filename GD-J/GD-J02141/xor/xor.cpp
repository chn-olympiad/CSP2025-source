#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s;
	int a[500005],top=0,ans=0; 
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>s;
		if(s!=0)a[top++]=s;
	}
	for(int i=1;i<top;++i){
		a[i]=a[i-1]^a[i];
	}
	for(int i=0;i<top;++i){
		if(a[i]==0||a[i]==k){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
