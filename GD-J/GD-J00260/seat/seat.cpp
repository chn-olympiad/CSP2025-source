#include<bits/stdc++.h>
using namespace std;
int n,m,ai,a[1005],num,x,y;
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin>>n>>m;
	cin>>ai;
	a[0]=ai;
	for(int i=1;i<=n*m-1;i++) cin>>a[i];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==ai){
			num=n*m-i;
			break;
		}
	}
	if(num%m!=0){
		x=num/m+1;
		if(x%2==1) y=num%m;
		else y=n-num%m+1;
	}
	else{
		x=num/m;
		if(x%2==0) y=num%m;
		else y=n-num%m+1;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
