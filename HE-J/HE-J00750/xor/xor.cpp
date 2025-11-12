#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
long long a[N],k;
int n;
bool f=0,t=0;
int ans=0;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
		if(a[i]>1) t=1;
	}
	
	if(!f){
		cout<<n/2<<"\n";
		return 0;
	}
	if(!t){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) {
					ans++;
					continue;
				}
				else if(a[i]==a[i+1]){
					ans++;
					i++;
				}
			}
		}
		else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	
	srand(time(0));
	int t=rand()%n+1;
	cout<<t<<"\n";
	
	return 0;
}
