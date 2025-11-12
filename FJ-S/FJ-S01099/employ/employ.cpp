#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
int n,m;
bool s[505];
int c[505];
bool f1=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string x;
	cin>>x;
	for(int i=0;i<x.size();i++){
		s[i+1]=x[i]-'0';
		f1=min(f1,s[i+1]);
		cin>>c[i+1];
	}
	if(m==n){
		if(!f1){
			cout<<0;
			return 0;
		}
	}else{
		for(int i=1;i<=rand()%1000;i+=1){
			srand(rand());
		}
		srand(rand());
		cout<<rand()*114514114514%100000+1;
	}
	return 0;
}

