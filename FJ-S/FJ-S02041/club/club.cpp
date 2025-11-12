#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[100001],n1,b,c;
long long sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		n1=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b>>c;
		}
		sort(a+1,a+n+1,cmp);
		for(int j=1;j<=n1;j++){
			sum+=a[j];
		}
		cout<<sum<<"\n";
	}
	return 0;
} 
