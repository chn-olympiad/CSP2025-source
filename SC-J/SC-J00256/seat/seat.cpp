#include<bits/stdc++.h>
using namespace std;
long long m,n,l[100005],x,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	cin>>x;
	for(int i=1;i<=m*n-1;i++){
		cin>>l[i];
		if(l[i]>x){
			cnt++;
		}
	}
	int h1,l1;
	if(cnt%m==0){
		l1=cnt/m;
	}else{
		l1=cnt/m+1;
	}
	h1=cnt%m;
	if(l1%2==1){
		if(h1==0){
			h1=m;
		}
	}else{
		if(h1==0){
			h1=1;
		}
		else{
			h1=m-h1+1;
		}
	}
	cout<<l1<<" "<<h1;
	return 0;
}