#include<bits/stdc++.h>
using namespace std;
int n,m,a[107],s,t,x,y;//x为列，y为行 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			t=i;
			break;
		}
	}
	if(t%n==0){
		x=t/n;
		if(x%2==1){
			y=n;
		}else y=1;
	}else{
		x=t/n+1;
		if(x%2==1){
			y=t%n;
		}else y=(n-(t%n)+1);
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
