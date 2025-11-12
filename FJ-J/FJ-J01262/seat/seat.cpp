#include<bits/stdc++.h>
using namespace std;
int n,m;
int getmysort(int n,int m){
	int my_score;
	cin>>my_score;
	int ans=1;
	for(int i=1;i<n*m;i++){
		int t;
		cin>>t;
		if(t>my_score){
			ans++;
		}
	}
	return ans;
}
int setting(int s,int n,int m){
	int row=s/(2*n)*2;
	if(s%(2*n)==0);
	else if(s%(2*n)<=n) row++;
	else row+=2;
	int col;
	if(s%(2*n)==0) col=1;
	else if(s%(2*n)<=n) col=s%(2*n);
	else col=2*n+1-s%(2*n);
	/* row     s/2n*2  s/2n+1*2   s/2n+2*2
		        0         1        (2n)
						  2        2n-1
						  3        2n-2
						  ...      ...
						  n        n+1
	*/
	cout<<row<<' '<<col;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	setting(getmysort(n,m),n,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
