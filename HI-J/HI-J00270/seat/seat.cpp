#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	int seat=1;
	for(int i=1;i<n*m;){
		int j;
		cin>>j;
		if(j>r){
			seat++;
		}
		i++;
	}
	if(seat%n==0){
		if((seat/n)&2==0){
			cout<<seat/n<<" "<<1; 
		}else{
			cout<<seat/n<<" "<<n; 
		}
	}else{
		cout<<seat/n+1<<" ";
		if((seat/n+1)&2!=0){
			cout<<seat%n;
		}else{
			cout<<n+1-(seat%n);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

