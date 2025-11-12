#include <bits/stdc++.h>
using namespace std; 
int n,m,pm=0,rdf,rpm,x=0,y=0;
int a[105];
bool cnt(int x,int y){
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	pm=n*m;
	for(int i=1;i<=pm;i++){
		cin>>a[i];
	}
	rdf=a[1];
	sort(a+1,a+pm+1,cnt);
	for(int i=1;i<=pm;i++){
		if(a[i]==rdf){
			rpm=i;
			break;
		}
	}
	if(rpm%n==0){
		x=rpm/n;
	}else{
		x=rpm/n+1;
	}
	if(x%2==1){
		if(rpm%n==0){
			y=n;
		}else{
			y=rpm%n;
		} 
	}else{
		if(rpm%n==0){
			y=1;
		}else{
			y=n-rpm%n+1;
		} 	
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
