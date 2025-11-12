#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,cnt=0;
	cin>>n>>m;
	vector<int>A;
	for(int i=0;i<n*m;i++){
		int back;
		cin>>back;
		A.push_back(back);
	}
	r=A[0];
	for(int i=1;i<n*m;i++)if(A[i]>r)cnt++;
	if((cnt/n+1)%2==1)cout<<(cnt/n+1)<<" "<<(cnt)%n+1;
	else cout<<(cnt/n+1)<<" "<<n-cnt%n;
	return 0;
}