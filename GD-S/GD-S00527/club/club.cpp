#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	struct name{
		int a,b,c;
	};
	int t;cin>>t;
	while(t){
		t--;
		int n;cin>>n;
		int sum=0;
		name k[n+10];
		for(int i=1;i<=n;i++)
		{
			cin>>k[i].a>>k[i].b>>k[i].c;
			sum+=max(k[i].a,max(k[i].b,k[i].c));
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
