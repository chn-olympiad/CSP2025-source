#include <bits/stdc++.h>
using namespace std;
int w[15][15];
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int temp=a[1];
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	for(int i=1;i<=n*m;i++){
		if(a[i]==temp){
			//cout<<i<<" ";
			int t=((i%n==0)?i/n:i/n+1);
			//cout<<t<<endl;
			if(t%2==1){
				//cout<<1<<endl;
				//cout<<i<<" "<<n<<" ";
				cout<<t<<" "<<((i%n==0)?n:i%n)<<endl;
			} 
			else{
				cout<<t<<" "<<n-((i%n==0)?n:i%n)+1<<endl;
			}
			break;
		}
	}
	return 0;
}
