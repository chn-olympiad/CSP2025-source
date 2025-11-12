#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,f,f1[1000001],f2[1000001],f3[1000001];
bool l(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>f1[j]>>f2[j]>>f3[j];
		}
		sort(f1,f1+n,l);
		sort(f2,f2+n,l);
		sort(f3,f3+n,l);
		for(int j=0;j<n/3+1;j++){
			f+=f1[j]+f2[j]+f3[j];
		}
		cout<<f;
	}
	return 0;
}
