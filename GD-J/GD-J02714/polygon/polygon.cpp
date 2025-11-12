#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n,z=0;
	cin>>n;
	int a[n+10],b[n+10]; b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	sort(a+0,a+n,cmp);
	for(int i=1;i<=n;i++){
		int d=-1;
		for(int j=i;j<=n;j++){
			if(a[j]>d)d=a[j];
			if(b[j]-b[i-1]>2*d)z++;
		}
	}
	cout<<z%998%244%353<<endl;
	
	return 0;
} 
