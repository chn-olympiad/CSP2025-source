#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005];
int n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
		//cout<<s[i]<<" ";
	}
	//cout<<endl;
	for(int i=0;i<=n;i++){
		//cout<<i<<" ";
		for(int j=i+1;j<=n;j++){
			//cout<<i<<" "<<j<<" "<< (s[j]^s[i] )<<" "<<k<<endl;
			if(i==j&&a[i]==k){
				ans++;
				//cout<<i<<" "<<j<<" "<< a[i]<<" "<<k<<endl;
			}
			if((s[j]^s[i])==k){
				//cout<<i<<" "<<j<<" "<< (s[j]^s[i] )<<" "<<k<<endl;
				ans++;
				i=j;
			}
		}
	}
	//cout<<(s[1]^s[2])<<endl;
	cout<<ans;
	return 0;
} 
//4 2 2 1 0 3 a2
//4 3 2 1 0 3 a2
//4 0 2 1 0 3 a1


