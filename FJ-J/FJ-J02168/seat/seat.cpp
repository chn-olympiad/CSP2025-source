#include<bits/stdc++.h>

using namespace std;

bool cmd(int x,int y){
	if(x>y){
		return 1;
	}
	return 0;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	int v=a[1];
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++){
		if(a[i]==v){
			int b=(i+n-1)/n;
			cout<<b<<" ";
			int c=i-n*(b-1);
		//	cout<<i<<" "<<n<<" "<<b<<endl;
			if(b%2==1){
				cout<<c;
			}
			else{
				cout<<n-c+1;
			}
		}
	}
	
	return 0;
}
