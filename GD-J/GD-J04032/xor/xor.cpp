#include<bits/stdc++.h>
using namespace std;
long long w(long long p,long long q){
	long long t=0;
	string u,n;
	while(p){
		u+=(p%2+'0');
		p/=2;
		
	}
	while(q){
		n+=(q%2+'0');
		q/=2;
		
	}
	if(u.size()<n.size()){
		while(u.size()<n.size()){
			u+='0';
		}
	}
	else if(u.size()>n.size()){
		while(u.size()>n.size()){
			n+='0';
		}
	}
	for(int i=0;i<=u.size();i++){
		if(u[i]!=n[i]){
			t+=pow(2,i);
		}
	}
	return t;
}
int main(){
	freopen("xor.in","r",in);
	freopen("xor.out","w",out);
	long long a,b,c;
	cin>>a>>b;
	vector<long long>k(1);
	for(long long i=1;i<=a;i++){
		cin>>c;
		k.push_back(c);
	}
	long long z=0,y=0,o=0;;
	if(k[1]==b){
		y++;	
	}else{
		z=k[1];
	}
	for(long long i=2;i<=a;i++){
		z=w(k[i],z);		
		if(z==b){
			z=0;
			y++;
		}
	}
	cout<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
