#include <iostream>
using namespace std;
int n,m,s[100001],c[100001],p[1000001],a,b,d;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i]
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(c[i]>c[i+1]){
			d=c[i];
			c[i+1]=c[i];
			c[i+1]=d;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==0){
			a++;
		}
	}
	if(a==n){
		cout<<0;
	}
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
