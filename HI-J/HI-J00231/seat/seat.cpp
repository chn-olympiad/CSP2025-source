#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=n*m,f=0,a1=0;
	int a[ans];
	for(int i=1;i<=ans;i++){
		cin>>a[i];
		a1=a[1];
	}
	for(int i=1;i<=ans;i++){
		for(int j=1;j<=ans;j++){
			if(a[j+1]>a[j]){
				swap(a[j],a[j+1]);
			}
		}
		
	}
	for(int i=1;i<=ans;i++){
		if(a[i]==a1){
			f=i;
		}
	}
	int m1=1;
	if(f>n){
		m1+=f/n;
		f=f%n; 
	}
	if(m1%2==0){
		f+=1;
	}
	cout<<m1<<" "<<f;
	
	
	
	return 0;
}
