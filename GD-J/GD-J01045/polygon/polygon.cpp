#include<bits/stdc++.h>
using namespace std;
int a[5010],l=0,m=0,w=0;
int n;
void ff(int r,int j,int k){
	j--;
	l+=a[r];
	m=max(a[r],m);
	if(j==0) return ;
	
	for(int i=r+1;i<=n;i++){
		ff(i,j,k);
		if(l>2*m&&k==a[r]){
			w++;
			//cout<<l<<" "<<m<<endl;	
		} 
		if(k==a[r]){
			l=k;
			m=k;	
		}
		
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3&&a[n]*2<a[1]+a[2]+a[3]){
		cout<<1;
		return 0;
	}
	int k;
	for(int i=1;i<=n;i++){
		for(int j=3;j<=n;j++){
			ff(i,j,a[i]);
		}
	}
	cout<<w;
	
	
	
}
