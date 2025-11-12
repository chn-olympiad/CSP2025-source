#include<bits/stdc++.h>
using namespace std;
int x,y,R,pw,a,b;
int fs[1002];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	cin>>fs[1];
	R=fs[1];
	int l=x*y;
	for(int i=2;i<=l;i++){
		cin>>fs[i];
	}
	sort(fs+1,fs+l+1);
	for(int i=1;i<=l;i++){
		if(fs[i]==R){
			pw=l-i+1;
			break;
		}
	}
	if(pw%x==0){
		a=pw/x;
		if(a%2==0){
			b=1;
		}else{
			b=x;
		}
	}else{
		a=pw/x+1;
		if(a%2==0){
			b=x-(pw%x)+1;
		}else{
			b=pw%x;
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}
