#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],dpa[100005][100005][3];
int club(){
	int n,sum=0; 
	cin>>n;
	for(int i=1; i<=n; ++i){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1; i<=n; ++i){
		sum+=max(a[i],max(b[i],c[i]));
	}
	return 0;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cout<<club()<<endl;
	}

	return 0;
}
