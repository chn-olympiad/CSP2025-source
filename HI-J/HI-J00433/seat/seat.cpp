#include<bits/stdc++.h>
using namespace std;
int n,m,seat;
int s[150];
int cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int temp=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==temp){
			seat=i;
			break;
		}
	}
	if(seat<=n){
		cout<<"1 "<<n;
		return 0;
	}
	else if(seat%n==0){//做某列最前或最后 
		if((seat/n)%2==0){//temp/n列 1排 
			cout<<seat/n<<" "<<1;
		}else{//temp/n列 最后一排 
			cout<<seat/n<<" "<<n;
		}
	}else{
		cout<<seat/n+1<<" ";
		if((seat/n+1)%2==0){
			cout<<n-seat%n+1;
		}else{
			cout<<seat%n;
		}
	}
	return 0;
}
