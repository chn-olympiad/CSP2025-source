#include <bits/stdc++.h>
using namespace std;
long long m,n,a[105],s=1,k=1,x=2,y=1,f=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				if(i==s) s=j;
				else if(j==s) s=i;
				swap(a[i],a[j]);
			}
		}
	}
	if(s==1){
		cout<<1<<" "<<1;
		return 0;
	}
	s-=2;
	while(s>0){
		if((1<x && x<m) || (f==1 && x==m) || (f==1 && x==1)){
			x+=k;
			f=0;
		}
		else if((x==m && f==0) || (x==1 && f==0)){
			y++;
			k=-k;
			f=1;
		}
		
		s--;
	}
	cout<<y<<" "<<x<<endl;
	return 0;
} 
