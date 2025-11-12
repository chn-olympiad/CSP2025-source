#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a=0,sum=0,cnt=0;
	cin>>n;
	for(int i=0; i<n; i++){
		if(i>a){
			a=i;
		}
		if(n>=3){
			sum=sum+i;
			if(sum>=2*a){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
