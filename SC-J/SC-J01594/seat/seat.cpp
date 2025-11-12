#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int seat[n*m+1];
	for(int i=1;i<=n*m;i++) cin>>seat[i];
	int a=seat[1],b;
	sort(seat+1,seat+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(seat[i]==a){
			b=i;
			break;
		}
	} 
	int c=b/n,r=b%n;
	if(r==0){
		cout<<c<<" "<<(c%2==0?1:n);
	}
	else{
		cout<<c+1<<" "<<((c+1)%2==0?n+1-r:r);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}