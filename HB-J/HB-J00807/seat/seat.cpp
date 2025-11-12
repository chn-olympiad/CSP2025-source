#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,cnt = 0;
	cin>>n>>m;
	cin>>a;
	for(int i = 1;i < n * m;i++){
		int x;
		cin>>x;
		if(x > a) cnt++;
	}
	int line = ceil((cnt + 1) * 1.0 / m);
	int row = cnt + 1 - (line - 1) * n;
	cout<<line<<" ";
	if(line % 2 == 0){
		cout<<n - row + 1<<endl;
	}
	else{
		cout<<row<<endl;
	}
	return 0;
}
