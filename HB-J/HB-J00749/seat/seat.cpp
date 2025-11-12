#include<bits/stdc++.h>
using namespace std;
int a[5000],m,n,cnt=1,ctm=1,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}
	//sort(a,a+n);
	k=a[1];
	//cout<<k<<" ";
	for(int i=1;i<=(m*n);i++){

		sort(a,a+n*m,cmp);
		//cout<<a[i]<<" ";

		if(k!=a[i]){
			//cnt++;	
			if(ctm%2==0){
				cnt--;
				if(cnt==1){
					ctm++;
					//cnt=cnt;
				}
			}
			else if(ctm%2==1){
				if(cnt!=n)
					cnt++;
				else if(cnt==n){
					ctm++;
				}
			}
		}
		if(a[i-1]==k)
			cout<<ctm<<" "<<cnt;
	}
	
	return 0;
}
