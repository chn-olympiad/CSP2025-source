#include<bits/stdc++.h>
using namespace std;
const int N=1100;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//CCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCFCCF 
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m,a[N];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int o=a[1],tmp,cmd;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			tmp=i;
			cmd=i;
		}
	}
	o=ceil(tmp*1.0/n);
	cout<<o<<" ";
	if(o%2){
		o=cmd%n;
	    if(o==0){
		    o=n;
    	}
	    cout<<o;
	}
	else{
		o=cmd%n;
	    if(o==0){
		    o=n;
    	}
    	o--;
	    cout<<n-o;
	}
	return 0;
} 
