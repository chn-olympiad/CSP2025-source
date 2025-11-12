#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[105];
bool cmp(int x,int y){
	if(x>y){
		return true;
	}
	else return false;
}
int s;
int r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<m*n;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+m*n,cmp);
	int x,y;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	if(r%n==0){
		x=r/n;
		if(x%2==0){
			y=1;
		}
		else y=n;
		cout<<x<<" "<<y;
	}
	if(r%n!=0){
		x=r/n+1;
		if(x%2==0){
			y=n+1-r%n;
		}
		else y=r%n;
		cout<<x<<" "<<y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
