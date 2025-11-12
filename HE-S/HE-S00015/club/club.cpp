#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int c[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,js=0;
	long long ans=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(b[j]==0||c[j]==0){
			    js++;
		    }
		}
		if(js==2*n){
			sort(a+1,a+n+1);
			for(int k=n/2+1;k<=n;k++){
				ans+=a[k];
			}
			cout<<ans<<endl;
			ans=0;
			goto c;
		}
		c:;
	}
	return 0;
} 
