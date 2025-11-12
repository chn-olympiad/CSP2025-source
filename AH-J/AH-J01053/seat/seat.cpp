#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int r=a[1],ri;
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ri=i;
			break;
		}
	}
	ri=(n*m)-ri+1;
	int lie=ceil(1.0*ri/(1.0*m)),hang;
	if(lie%2==0){
		hang=1;
		hang+=lie*m-ri;
	}else{
		hang=m;
		hang-=lie*m-ri;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
