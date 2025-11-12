#include<bits/stdc++.h>
using namespace std;
int n,m,len;
struct node{
	int a,i;
} a[200];
bool my(node q,node w){
	return q.a>w.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i].a;
		a[i].i=i;
	}
	sort(a+1,a+1+len,my);
	for(int i=1;i<=len;i++){
		if(a[i].i==1){
			int e,r,t,y;
			if(i%n==0)e=i/n;
			else e=i/n+1;
			if(e%2==1){
				if(i%n==0) r=n;
				else r=i%n;
			} 
			else{
				if(i%n==0) r=1;
				else r=n-i%n+1;
			}
			cout<<e<<" "<<r;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}