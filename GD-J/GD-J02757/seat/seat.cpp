#include<bits/stdc++.h>
using namespace std;
int a[110];
int cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int o=n*m;
	for(int i=1;i<=o;i++){
		cin>>a[i];
	}
	for(int i=2;i<=o;i++){
		if(a[i]>a[1]) cnt++;
	}
	//cout<<cnt<<endl;
	int c;
	if(cnt%n==0) c=cnt/n;
	else c=cnt/n+1;
	int d=c%2;
	int r;
	if(d){
		int e=cnt-n*(cnt/n);
		if(e==0){
			r=m;
		}
		else{
			r=e;
		}
	}
	else{
		int f=cnt-n*(cnt/n);
		if(f==0){
			r=1;
		}
		else{
			r=n+1-f;
		}
	}
	cout<<c<<' '<<r; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
