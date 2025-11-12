#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s,k,p=1,I,J;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+s+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[s]==k){
				p=0;
				I=i;
				J=j;
				break;
			}
			s--;
		}
		if(p==0){
			break;
		}
		i++;
		for(int j=n;j>=1;j--){
			if(a[s]==k){
				p=0;
				I=i;
				J=j;
				break;
			}
			s--;
		}
		if(p==0){
			break;
		}
	}
	cout<<I<<" "<<J;
	return 0;
}
