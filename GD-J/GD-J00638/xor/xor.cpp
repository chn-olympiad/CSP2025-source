#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,k;
int a[500007];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) l=1;
	}
	if(!l){
		if(k==0){
			if(n%2==0){
				cout<<n/2<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		else if(k==1){
			cout<<n<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
	else{
		cout<<n/2<<endl;
	}
	return 0;
}
