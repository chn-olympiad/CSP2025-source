#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100010],c=1,r=1,R=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n+1);
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]!=R){
				r++;
				if(r>n){
					c++;
					r--;
					
				} 
			}
			else break;
		}
	}
	cout<<r<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
