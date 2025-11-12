#include<bits/stdc++.h>
using namespace std;
int m,n,s[105],r;
float ma,na,rx;
bool cmp(int x,int y){
	if(x>y) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}	
	r=s[0];
	sort(s,s+m*n,cmp);	
	for(int i=0;i<m*n;i++){
		if(s[i]==r) {
			rx=i+1;
			break;
		} 
	}
	ma=ceil(rx/m);
	if(int(ma)%2==0)  na=n-(int(rx)%n)+1;
	else if(ma==1)  na=rx;
	else na=int(rx)%n;
	cout<<ma<<" "<<na;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

