#include<bits/stdc++.h>
using namespace std;
long long in[100005];
long long n,m,r;
long long l=1,h=1;
bool cmp(long long a,long long b){
	return a>b;
}
bool ch(){
	for(long long i=1;i<n*m;i++){
		if(in[i]<in[i+1]) return 0;
	}
	return 1;
}
void ssss(){
	while(!ch()){
		for(long long j=1;j<n*m;j++){
			if(in[j]<in[j+1]) swap(in[j],in[j+1]);
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>in[i];
		if(i==1) r=in[i];
	}
	ssss();
	for(long long i=1;i<=n*m;i++){
		if(in[i]==r){
			r=i;
			break;	
		}
		
	}
	l=ceil(double(r)/double(n));
	h=r-((l-1)*n);
	if(l%2==0){
		h=n-h+1;
	}
	cout<<l<<" "<<h;

	return 0;
} 
