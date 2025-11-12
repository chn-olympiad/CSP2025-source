#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int ss[10101]={};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>ss[i];
	}
	int a1=ss[1];
	
	sort(ss+1,ss+n*m+1);
	cout<<endl;
	int t=0;
	for(int i=n*m;i>0;i--){
		t++;
		if(ss[i]==a1){
			break;
		}
	}
	int c;
	if(t%n>0)c=(t/n)+1;
	else c=t/n;
	int r=t%(2*m);
	if(r>n){
		r=2*n+1-r;
	}
	cout<<c<<' '<<r;
}
