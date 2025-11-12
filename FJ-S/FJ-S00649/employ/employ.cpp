#include<bits/stdc++.h>
using namespace std;
char s[3];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c,ans=0,sum=0,a=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c>=0){
			a++;
		}
	} 
	cout<<a<<" "<<n-a<<endl;
	for(int i=1;i<=a;i++){
		ans+=i; 
	} 
	for(int i=n-a;i>=1;i--){
		sum+=i; 
	} 
	cout<<ans<<" "<<sum<<endl; 
	if(ans==0){
		ans++;
	}
	else if(sum==0){
		sum++;
	}
	else if(n-a==2){
		sum--;
	}
	cout<<(((ans*sum)%998)%244)%353;
	return 0;
} 
