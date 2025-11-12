#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101]={0},s,b[101]={0},z=1,c,r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	s=a[0];
	for(int i=0;i<n*m;i++)b[a[i]]=a[i];		
	
	for(int i=100;i>=0;i--){
		if(b[i]!=0){
			if(b[i]==s)break;
			z++;
		}
	}
	if((z+1)%n==0)r=n;
	else r=(z+1)%n+1;
	if(z%n!=0)c=z/n+1;
	else c=z/n;
	if((z/n)%2==0)cout<<c<<' '<<(n+1)-r;
	else cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
