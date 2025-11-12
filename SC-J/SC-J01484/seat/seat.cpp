#include<bits/stdc++.h>
using namespace std;
int n,m,d=1,c,r,i,j;
int b[11][11];
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])d++;
	}
	i=1;
	j=1;
	while(d!=0){
		if(d==1){
			cout<<j<<" "<<i;
			break;
		}
		if(j%2==1){
			if(i!=n)i++;
			else j++;
		}
		else {
			if(i!=1)i--;
			else j++;
		}d--;
	}
	return 0;
}
