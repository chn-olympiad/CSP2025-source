#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	t=n*m;
	int a[101];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],y;
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;
		}
	}
	if(y==n){
		cout<<"1 "<<n<<endl;
		return 0;
	}else if(y%n==0){
		cout<<y/n<<" 1"<<endl;
	}else{
		int c=y/n;
		int r=y%n;
		if(c%2==0){
			cout<<c+1<<" "<<r<<endl;
		}else{
			cout<<c+1<<" "<<n<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
