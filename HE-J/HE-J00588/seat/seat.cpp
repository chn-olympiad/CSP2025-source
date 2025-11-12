#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans=0,s=0,y=0,sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			sum=n*m-i+1;
			break;
		}
	}
	s=sum/n;
	y=sum%n;
	if(y>0){
		s++;
		if(s%2==0){
			y=n-y+1;
		}
	}else{
		y=n;
	}
	cout<<s<<" "<<y;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
