#include<bits/stdc++.h>

using namespace std;

int n,m,tot,ans,ans_1,v;
int a[505],b[505];
char f[505];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(f[i]=='0'){
			tot++;
			b[tot]=i;
		}
	}
	if(n-tot<m){
	//	cout<<"3 "<<tot<<" "<<endl;
		cout<<ans;
		return 0;
	}
	int c;
	for(int i=1;i<=n;i++){
		cin>>c;
		a[c]++;
	}
/*	for(int i=1;i<=tot;i++){
	//	cout<<"1 "<<tot<<" "<<a[i]<<" "<<b[i]<<endl;
		if(a[i]>=b[i]){
			v+=a[i]-b[i]-1;
			ans_1+=(a[i]+b[i]-a[i]+1)*b[i]/2;
		//	cout<<(a[i]+b[i]-a[i])*(b[i]-1)/2<<endl;
		}
		else{
			b[i+1]+=b[i]-a[i]-1;
			v--;
			a[i+1]-=1;
			ans_1+=(a[i]+1)*a[i]/2;
		//	cout<<"2 "<<a[i]+1<<" "<<a[i]<<" ";
		//	cout<<(a[i]+1)*a[i]/2<<endl;
		}
		ans_1%=998244353;
	}
	if(n-v<m){
	//	cout<<1<<endl;
		cout<<ans;
	}
	else{
		if(b[tot]<n){
			ans_1+=(n-v-b[tot]+n-v-b[tot]-n+tot+1)*(n-tot)/2;
		}
		cout<<ans_1%998244353;
	}
	*/
	
	cout<<(n-a[0]+1)*(n-a[0])/2;
	
	return 0;
}
