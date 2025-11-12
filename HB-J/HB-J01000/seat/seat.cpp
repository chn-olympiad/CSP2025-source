#include<bits/stdc++.h>
using namespace std;
int n,m;
int hang,lie,i;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=1;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[1]<a[i]) s++;
	}
	if(m==1){
		cout<<s<<" "<<1;
		return 0;
	}else if(n==1){
		cout<<1<<" "<<s;
		return 0;
	}
	if(s<=n){
		lie=1;
	}
	else{
		if(s%n==0){
			lie=s/n;
		}else{
			lie=s/n+1;
		}
	}
	int y=s%n;
	if(lie%2!=0){
		hang=y;
		if(hang==0){
			hang=n;
		}
	}
	else{
		if(y==0){
			y=n;
		}
		hang=n-y+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
}


