#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n*m],c;
	cin>>c;
	s[0]=c;
	for(int i = 1;i<n*m;i++){
		cin>>s[i];
	}
	sort(s+0,s+n*m);
	int x1=0,x2=0,x3=0,x4=n-1,x5=m-1,x6=1,x7=1,x8,x9,x10;
	for(int i = n*m-1;i>=0;i--){
		if(s[i]==c) break;
		if(x1==x3||x1==x4){
			if(x6){
				x6=0;
				x1+=x7;
			}else{
				x6=1;
				x2++;
				if(x7==1){
					x7=-1;
				}else{
					x7=1;
				}
			}
		}else{
			x1+=x7;
		}
	}
	cout<<x2+1<<' '<<x1+1;
	return 0;
}
