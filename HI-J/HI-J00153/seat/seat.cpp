#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0,hang=1,lie=1,r;
	int b[n*m];
	if(n==1 && m==1){
		cout<<1;
	}
	else {
		for(int i=0;i<n*m;i++){
			cin>>b[i];
			r=b[1];
			if(b[i]>r){
				sum++;
			}
		}
		if(sum<n){
			cout<<1<<" "<<sum;
		}
		else{
			for(int i=0;i<n*m;i++){
				if(sum%n==0){
					lie=sum/n;
					break;
				}
				sum++;
			}
			for(int i=0;i<m*n;i++){
				if(sum-n<n){
					hang=sum-n;
					break;
				}
				sum-=n;
			}
			cout<<lie<<" "<<hang;
		}
	}
	
	return 0;
}

