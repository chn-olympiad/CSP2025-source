#include<bits/stdc++.h>
using namespace std;
int n,m,score,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>score;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>score){
			cnt++;
		}
	}
	if(cnt%n==0){
		if((cnt/n)%2==0){
			cout<<cnt/n<<" "<<1;
		}
		else{
			cout<<cnt/n<<" "<<n;
		}
	}
	else{
		if((cnt/n+1)%2==0){
			cout<<cnt/n+1<<" "<<n-(cnt%n)+1;
		}
		else{
			cout<<cnt/n+1<<" "<<cnt%n;
		}
	}
	return 0;
}

