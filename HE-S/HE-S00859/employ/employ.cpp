#include<iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c,p;
	string s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s=='0'){
			n-=1;
		}
	}
	for(int l=1;l<=n;i++){
		cin>>c;
		if(c==0){
			n-=1;
		}
	}
	if(n=>m){
		p+=1;
	}
	cout<<p;
	return 0;
}
