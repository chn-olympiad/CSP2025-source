#include<bits/stdc++.h>
using namespace std;
int n,v=0;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx,he;
	for(int i=1;i<n;i++){
		maxx=max(a[i],a[i+1]);
		he+=a[i];
		he+=a[i+1];
		for(int j=i+2;j<=n;j++){
			maxx=max(a[j],maxx);
			he+=a[j];
		    if(maxx*2<he){
		    	v++;
			}
		}
	}
	cout<<v;
	return 0;
}
