#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[510];
string b;
bool f=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>b;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) f=false;	
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	long long ans=0;
	if(f){
		int ans=0;
		for(int i=1;i<=n;i++){
			int temp=0;
			for(int j=i;j;j<=n;j++){
				for(int k=j;k<=n;k++){
					if(a[k]<j) continue;
					else temp++; 
				}
				temp-=m;
			}
			ans=((temp*temp)/2)998244353+ans;
			ans=ans%998244353;
		} 
	}
	cout<<ans;
	return 0;

}

