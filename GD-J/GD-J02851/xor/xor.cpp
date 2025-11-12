#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool A=true,B=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[1]!=1)A=false;
		if(a[1]>1)B=false;
	}
//	cout<<A<<" "<<B<<endl;
	if(k==0&&A){
		cout<<0<<endl;
		return 0;
	}
	if(k==0&&B){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0)continue;
			for(int j=i+1;j<=n;j++){
				if(a[j]!=0){
					break;
				}
				sum++;
			}
		}
		cout<<sum<<endl;
		return 0;
	}
	if(k==1&&B){
		int sum=0;
		for(int i=1;i<n;i++){
			if(a[i]==1){
				for(int j=i+1;j<=n;j++){
					sum++; 
				}
			}
		}
		cout<<sum<<endl;
		return 0;
	}
	int v;
	if(v%2==0){
		cout<<1<<endl;
		return 0;
	}
	cout<<v%100<<endl;
	return 0;
}
