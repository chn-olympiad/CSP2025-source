#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	short a[n*m]={};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	short R = a[0];
	sort(a, a+n*m, greater<short>());
	int seat = find(a, a+n*m, R)-a+1;
	if (seat%n==0){
		if ((seat/n)%2==0){
			cout<<seat/n<<" 1"<<endl;
			return 0;
		}else{
			cout<<seat/n<<" "<<m<<endl;
			return 0;
		}
	}
	short row = ceil(seat/(n*1.0));
	if (row%2==0){
		cout<<row<<" "<<n-(seat-(row-1)*n)+1<<endl;
		return 0;
	}else{
		cout<<row<<" "<<seat-(row-1)*n<<endl;
		return 0;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}