#include <bits/stdc++.h>

using namespace std;

int a[105];

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+m*n);
	for(int i=0;i<n*m;i++){
		int d=n*m-i-1;
		//cout<<i+1<<" "<<a[d]<<endl;
		if(a[d]==b){
			int c=i/n+1;
			cout<<c<<" ";
			if(c%2==0){
				cout<<n-i%n;
				break;
			}else{
				cout<<i%n+1;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
