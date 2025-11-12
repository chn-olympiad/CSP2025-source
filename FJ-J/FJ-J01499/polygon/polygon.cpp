#include<bits/stdc++.h>
using namespace std;

int n,m=0,a[10005],c=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]<a[j+1])swap(a[j],a[j+1]);
		}
	}
	if(c>a[0])m+=1;
	cout<<m;
	return 0;
}
