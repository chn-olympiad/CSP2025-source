#include<bits/stdc++.h>
using namespace std;
int s[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	s[0]=r;
	for(int i=1;i<n*m;i++){
		cin>>s[i];
	}
	sort(s,s+n*m-1);
	int ji=0;
	for(int i=n*m-1;i>=0;i--){
		if(s[i]==r){
			ji=n*m-i-1;
		}	
	}
	if(ji%n==0){
		cout<<ji/n<<" ";
		if((ji/n)%2==0){
			cout<<1;
		}else{
			cout<<m;
		}
	}else{
		cout<<ji/n+1<<" ";
		if((ji/n+1)%2==0){
			cout<<m-(ji-ji/n*n)+1;
		}else{
			cout<<ji-(ji/n*n);
		}
	}
	return 0;
}
//AFO???