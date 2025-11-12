#include<bits/stdc++.h>
using namespace std;
int n,m,s,b,n1,m1;
int a[105],mp[11][11];
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==0){
		 	for(int j=m;j>=1;j--){
			 	b++;
			 	if(a[b]==s){
					n1=i;
					m1=j;
					break;
				}
				mp[i][j]=a[b];
			}
		}else{
			for(int z=1;z<=m;z++){
				b++;
				if(a[b]==s){
					n1=i;
					m1=z;
					break;
				}
				mp[i][z]=a[b];
			}	
		}
	}
	cout<<n1<<" "<<m1;
	return 0;
}
