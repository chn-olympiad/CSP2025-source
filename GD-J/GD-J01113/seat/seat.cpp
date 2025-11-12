#include<iostream>
#include<vector>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,s;
	cin>>n>>m;
	s=n*m;
	vector<int> a(s+1);
	cin>>a[0];
	int r=1;
	for(int i=1;i<s;i++){
		cin>>a[i];
		if(a[0]<a[i]){
			r++;
			//cout<<a[i];
		}
	}
	//cout<<r<<endl;
	int y=(r-1)/n+1,x=y%2==1 ? (r-1)%n+1 : n-(r-1)%n;
	cout<<y<<" "<<x;
	return 0;
}

/*
1 4 5
2 3 6

1 6 7 12
2 5 8 11
3 4 9 10

 1  8   9  16  17
 2  7  10  15  18
 3  6  11  14  19
 4  5  12  13  20
 */
