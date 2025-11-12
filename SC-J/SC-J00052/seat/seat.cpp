#include <bits/stdc++.h>
using namespace std;
int s[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sortt=1;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
		if(s[i]>s[1]){
			sortt++;
		} 
	}
	if(sortt==1) {
		cout<<"1 1";
		return 0;
	}
	else if(sortt==n*m){
		cout<<n<<" "<<m;
		return 0;
	}
	else if((sortt-1)%n==0){
		if(((sortt-1)/n)%2==0){
			cout<<(sortt-1)/n+1<<" "<<1;
		}
		else cout<<sortt/n+1<<" "<<n;
		return 0;
	}
	else{
		if((sortt-1/n)%2==0){
			if(sortt%n==0)
				cout<<(sortt-1)/n+1<<" "<<sortt%(n+1);
			else 
			cout<<(sortt-1)/n+1<<" "<<sortt%n;
		}
		else cout<<(sortt-1)/n+1<<" "<<n-sortt%n;
	}
	return 0;
}
//rp++