#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int seat;
	int m,n;
	cin>>n>>m;
	int temp;
	int num=1;
	cin>>seat;
	for(int i=1;i<n*m;i++){
		cin>>temp;
		if(temp>seat)num++;
	}
	
	int m1=num/n;
	if(num%n!=0){
		m1++;
	}
	
	int n1=num%n;
	if(m1%2==0){
		n1=n-n1+1;
	}
	if(n1==0)n1=n;
	cout<<m1<<" "<<n1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
