#include<bits/stdc++.h> 
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[106]={ },n,m,b=0,seat=0,y=0,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	//cout<<b<<endl;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			seat=i+1;
			//cout<<seat<<endl;
			break;
		}
		
	}
	if(seat%n==0 && seat/n%2!=0){
		cout<<seat/n<<" "<<m; 
	}
	else if(seat%n==0 && seat/n%2==0){
		cout<<seat/n<<" "<<"1";
	}
	else if((seat-1)%n==0 && seat/n%2!=0){
		cout<<seat/n+1<<" "<<m;
	}
	else if((seat-1)%n==0 && seat/n%2==0){
		cout<<seat/n+1<<" "<<"1";
	}
	else {
		cnt=seat/n+1;
		//cout<<cnt<<endl;
		y=seat%n;
		if(y==0)y=n;
		else if(cnt%2==0){
			y=n-y;
		}
		cout<<cnt<<" "<<y;
	}
	return 0;
}
