#include<bits/stdc++.h>
using namespace std;
int main(){
	//feropen("number.in","r",stdin);
	//feropen("number,out","w",stdout);
	int n,m;
	cin>>n;
	int a,b,c;
	if(n>=0||n<=9){
		cout<<n;
	}
	if(n%10<=9){
		int w,e;
		w=n%10;
		e=n-w*10;
		if(w>e){
			n=w*10+e;
			cout<<n;
		}
		else{
			n=e*10+w;
			cout<<n;
		}
	}
	if(n/100>=99){
		
		a=n%100;
		b=(n-a)%10;
		c=n-a-b;
		
		if(a>b){
			if(b>c){
				n=a*100+b*10+c;
				cout<<n;
			}
			if(b<c&&c<a){
				n=a*100+c*10+b;
				cout<<n;
			}
			else{
				n=a*100+c*10+b;
				cout<<n;
			}
		}
		if(b>c){
			if(a<b&&a<c){
				n=b*100+c*10+b;
				cout<<n;
			}
			if(a<b&&a>c){
				n=b*100+a*10+c;
				cout<<n;
			}
			 
		}
		cout<<n;
		
	}
} 
