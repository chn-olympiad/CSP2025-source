#include<bits/stdc++.h>
using namespace std;
int n,m,b[110],pp,r,ii=0,jj=1;
bool ud;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	pp=n*m;
	for(int i=1;i<=pp;i++) cin>>b[i];
	r=b[1];
	sort(b+1,b+pp+1,cmp);
	for(int i=1;i<=pp;i++){
		if(!ud) ii++;
		else ii--;
		if(ii>n){
			ii=n;
			jj++;
			if(ud) ud=0;
			else ud=1;
		}if(ii<1){
			ii=1;
			jj++;
			if(ud) ud=0;
			else ud=1;
		}if(b[i]==r){
			cout<<jj<<' '<<ii;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
