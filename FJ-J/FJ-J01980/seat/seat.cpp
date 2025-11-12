#include<bits/stdc++.h>
using namespace std;
int c[10000],d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>c[i];
	}
	d=c[1];
	sort(c+1,c+1+a*b);
	for(int i=1;i<=a*b;i++){
		if(c[i]==d){
			int w=a*b-i+1;
			int k=ceil(w*1.0/a);
			int l;
			if(k%2==1){
				l=w%a;
				if(l==0){
					l=a;
				}
			}
			else{
				l=a-w%a+1;
				if(l>a){
					l=1;
				}
			}
			cout<<k<<" "<<l;
		}
	}
	return 0;
}
