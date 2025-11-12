#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[105],cnt,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	int c=b[0];
	cnt=1;
	sort(b,b+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(b[i]!=c){
			cnt++;
		}else{
			break;
		}
	}
	l=cnt/n;
	if(cnt%n!=0){
		l++;
	}
	if(l==0){
		l++;
	}
	h=cnt-(l-1)*n;
	cout<<l<<" ";
	if(l%2==0){
		cout<<n-h+1;
	}else{
		cout<<h;
	}
	return 0;
}
