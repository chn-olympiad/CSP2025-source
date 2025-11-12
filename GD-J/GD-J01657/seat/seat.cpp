#include<bits/stdc++.h>
using namespace std;
int m,n,R,a[105],aa;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat2.in","r",stdin);
	freopen("seat2.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}	
	R=a[1];	
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			aa=i;
		}
	}
	//cout<<n<<" "<<m<<"\n";
	int lie=1;
	while(aa>n){
		aa-=n;
		lie++;
	}
	if(lie%2==1)
	cout<<lie<<" "<<aa;
	else
	cout<<lie<<" "<<m-aa+1;
	return 0;
} 
