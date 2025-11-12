#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
		}
	}
	int b=r/n+1;
	if(r%n==0){
	    cout<<r/n<<' ';
		if((r/n)%2==1){
			cout<<n;
		}
		else{
			cout<<"1";
		}
	}
	else{
	    if((r/n)%2==0){
			cout<<b<<' '<<r%(n*b)-(r/n)*n;
		}
		else{
			cout<<b<<' '<<n*b-r%(n*b)+1;
		}
	}		
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
