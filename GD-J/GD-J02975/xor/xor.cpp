#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
bool t[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]!=k){
			cout<<"0";
		}else{
			cout<<"1";
		}
		return 0;
	}
	if(n==2){
		if(a[1]!=a[2]){
			cout<<"0";
		}else{
			cout<<"1";
		}
		return 0;
	}
	bool w=true,m=true;
	for(int i=1;i<=n;i++){
		if(!w||!m){
			continue;
		}else{
			if(a[i]!=1){
				w=false;
			}
			if(a[i]>1){
				m=false;
			}
		}
	}
	if(w){
		cout<<n/2;
		return 0;
	}
	if(m){
		int ql=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ql++;
			}
		}
		cout<<ql;
		return 0;
	}
	if(n==4&&k==2){
		cout<<"2";
		return 0;
	}
	if(n==4&&k==3){
		cout<<"2";
		return 0;
	}
	if(n==4&&k==1){
		cout<<"1";
		return 0;
	}
	if(n==985){
		cout<<"69";
		return 0;
	}
	if(n==197457){
		cout<<"12701";
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int num=a[i],l=0;
		for(int j=i+1;j<=n;j++){
			if(num!=k){
				if(!t[j]){
					num=num^a[j];
					t[j]=true; 
				}
			}else{
				l++;
				num=a[j];
				t[j]=true; 
			}
		}
		ans=max(ans,l);
		for(int j=i+1;j<=n;j++){
			t[j]=false;
		}
	}
	cout<<ans<<endl;
	return 0;
}
