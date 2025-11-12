#include<bits/stdc++.h>
using namespace std;

int n,m;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	int top = 1;
	
	int a1;
	cin>>a1;
	
	for(int i=1;i<n*m;i+=1){
		int temp;
		scanf("%d",&temp);
		if(temp>a1)top+=1;
	}
	
	int li;
	
	if(top%n == 0){
		if(top/n%2==0){
			cout<<top/n<<" "<<1;
		}
		else{
			cout<<top/n<<" "<<m;
		}
	}
	else{
		if((top/n+1)%2==0){
			cout<<top/n+1<<" "<<m+1-(top%n);
		}
		else{
			cout<<top/n+1<<" "<<top%n;
		}
	}
	
	return 0;
	
}
