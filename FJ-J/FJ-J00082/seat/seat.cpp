#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	int c=a[1];
	int d=0;
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--){
		if(a[i]==c){
			d=b-i+1;
		}
	}
	int lie=d/n;
	int hang=d%n;
	if(lie%2!=0 && hang!=0){
		hang=n-hang+1;
		lie++;
	}else if(lie%2!=0 && hang==0){
		hang=n;
	}else if(lie%2==0 && hang==0){
		hang=1;
	}else if(lie%2==0 && hang!=0){
		lie++;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
