#include<bits/stdc++.h> 
using namespace std;
const int N=6000;
int a[N],b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	
	sort(b+1,b+n+1);
	
	a[1]=b[1];
	for (int i=2;i<=n;i++){
		a[i]=b[i]+a[i-1];
	}
	
	int s=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			if (a[i]-a[j-1]>b[i]*2){
				s++;
			}
			
		}
	}
	cout<<s;
	
	return 0;
}
