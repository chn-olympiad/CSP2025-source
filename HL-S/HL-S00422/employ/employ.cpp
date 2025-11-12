#include<bits/stdc++.h>
using namespace std;
string a;
int y=0,m=0,c,d,h,f[110000];
void x(int b,int t,int u){
	
	if(b==h){
		if(m==d){
			y++;
		}
		m=0;
		return;
	}
	for(int i=0;i<=h;i++){
		if(u!=i){
			if(a[t]=='1' && f[i]>=t){
				m++;
			}
			x(b+1,t+1,i);
		}
		
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>c>>d;
	cin>>a;
	for(int i=0;i<c;i++){
		cin>>f[i];
	}
	h=c;
	x(0,0,-1); 
	cout<<y;
	return 0;
} 
