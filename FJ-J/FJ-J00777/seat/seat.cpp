#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id,p;
}a[105];
bool cmp(node x,node y){
	return x.p>y.p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].p;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cnt=i;
			break;
		}
	}
	
	int t=cnt%(2*n),gr=(cnt+2*n-1)/(2*n); 
	if(t==0)t+=2*n; 
	
	int ansy=0;
	int ansx=2*gr;
	if(t<=n){
		ansy+=t;
		ansx--;
	}else{
		ansy+=2*n-t+1;
	}
	
	cout<<ansx<<" "<<ansy<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
