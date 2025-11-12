#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int a[N],n,k;
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	//feropen  freeopen  "xor.cpp"  soutdt
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(1==2){
		cout<<"CSP2025 RP++!"<<endl; 
	}
	if(n<=2){
		int x,y;
		cin>>x>>y;
		if(x==k||y==k||x^y==k){
			if(x==k&&y==k){
				cout<<"2"<<endl;
			}else{
				cout<<"1"<<endl;
			}
		}
	}else{
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
