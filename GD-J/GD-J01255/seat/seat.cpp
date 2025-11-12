#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int rscore,grade=1;
	cin>>rscore;
	for(int i=1;i<=n*m-1;i++){
		int a;
		cin>>a;
		if(a>rscore) grade++;
	}
	int k=(grade-1)/n;
	int col=k+1,row;
	if(col%2==0){
		row=n+1-((grade-1)%n+1);
	}
	else{
		row=(grade-1)%n+1;
	}
	cout<<col<<" "<<row<<endl;
	return 0;
}
