#include<bits/stdc++.h>
using namespace std;
bool flag(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[n+10];
		int b,c;
		for(int i=0;i<n;i++) cin>>a[i]>>b>>c;
		sort(a,a+n,flag);
		int cnt=0;
		for(int i=0;i<n/2;i++) cnt+=a[i];
		cout<<cnt<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
