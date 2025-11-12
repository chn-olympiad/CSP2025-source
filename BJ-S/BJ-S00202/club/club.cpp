#include<bits/stdc++.h>
using namespace std;
int k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>k;
	for(int i=1;i<=k;i++){
		int n;
		cin>>n;
		int sum=0;
		for(int j=1;j<=n;j++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&a>=c)
				sum+=a;
			else if(b>=a&&b>=c)
				sum+=b;
			else if(c>=b&&c>=a)
				sum+=c;
		}
		cout<<sum<<endl;
	}
	return 0;
}
