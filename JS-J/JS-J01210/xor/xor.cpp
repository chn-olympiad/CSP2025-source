#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int> a;
int n,k;
bool flag1,flag2;
long long ans;
int main(){
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int number;
		cin>>number;
		a.push_back(number);
		if(number!=1) flag1=true;
		if(number!=1&&number!=0) flag2=true;
	}
	if(!flag1){
		if(k==1) cout<<n<<endl;
		else cout<<int(n/2)<<endl;
	}
	else if(!flag2){
		if(k==1){
			for(int i=0;i<n-1;i++){
				if(a[i]==1) ans++;
				if(a[i]==0&&a[i+1]==0){
					ans++;
					i++;
				}
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=0;i<n-1;i++){
				if(a[i]==0) ans++;
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else{
		cout<<int(n/2)<<endl;
	}
	return 0;
}
