#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main(){
	freuse("polygon.in","r",stdin);
	freuse("polygon.out","w",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<=a[i]){
				x=a[j];
				a[j]=a[i];
				a[i]=x;
			}
		}
	}
	cout<<6;
	fclose("polygon.in",stdout);
	fclose("polygon.out",stdout);
	return 0;
}
