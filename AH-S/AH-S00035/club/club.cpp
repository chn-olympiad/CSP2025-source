#include<bits/stdc++.h>
using namespace std;
int a1[10000],a2[10000],a3[10000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,maxx=-1,sum=0;
	cin>>t;
	int a[t+1];
	for(int i=1;i<=t;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			cin>>a1[j]>>a2[j]>>a3[j];
			maxx=max(a1[j],max(a2[j],a3[j]));
			sum+=maxx;
		}
		cout<<sum<<endl;
		sum=0;
		maxx=-1;
	}
	return 0;
}
