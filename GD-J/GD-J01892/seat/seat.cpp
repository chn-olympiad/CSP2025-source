#include <bits/stdc++.h>
using namespace std;
int n,m,mar,q[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>mar;
	q[1]=mar;
	for (int i=2;i<=n*m;i++){
		cin>>q[i];
	}
	sort(q+1,q+n*m+1,greater<int>());
	int i=1,j=1;
	for (int k=1;k<n*m;k++){
		//cout<<i<<" "<<j<<endl;
		if (q[k]==mar){
			cout<<j<<" "<<i;
			return 0;
		}
		else if (k%n==0){
			//cout<<11<<" ";
			j++;
		}
		else if((k/n)%2==0){
			//cout<<22<<" ";
			i++;
		}
		else if ((k/n)%2==1){
			//cout<<33<<" ";
			i--;
		}
		
	}
	cout<<j<<" "<<i;
	
	return 0;
}
