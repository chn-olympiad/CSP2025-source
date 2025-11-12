#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool f=true,f1=true;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i]!=0) f=false;
			if(c[i]!=0) f1=false;
		}
		if(f){
			int sum=0;
			sort(a,a+n+1);
			for(int i=n;i>n/2;i--)
				sum+=a[i];
			cout<<sum;
			continue;
		} 
		else if(f1){
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=max(b[i],a[i]);
			cout<<sum<<"\n";
			continue;
		}
	}
	return 0;
} 
