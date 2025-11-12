#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int a1=0;
	cin>>a1;
	int grade=0;
	for(int i=1;i<n*m;i++){
		int a=0;
		cin>>a;
		if(a>a1){
			grade+=1;
		}
	}
	int x=floor(grade/n)+1;
	cout<<x<<" ";
	if(x%2==0){
		cout<<n-grade%n<<endl;
	}else{
		cout<<grade%n+1<<endl;
	}
}
