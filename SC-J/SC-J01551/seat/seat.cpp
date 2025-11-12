#include<bits/stdc++.h>
using namespace std;
int p[1005];
int ans[105][105];
int n,m;
int h;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		cin>>p[i];
	}
	int o=p[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
		if((p[j])<(p[j+1])){
			h=p[j];
			p[j]=p[j+1];
			p[j+1]=h;
		}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(p[i]==o){
			h=i;
		}
	}
	int b=(h+m-1)/m;
	if(m==1){
		cout<<1<<" "<<h; 
	}else{
	if(b%2==0){
		cout<<b<<" "<<b*m-h+1;
	}else{
		if(h%n!=0){
		cout<<b<<" "<<h%m;
		}else{
		cout<<b<<" "<<m;
		}		 
	}
	}
	return 0;
}