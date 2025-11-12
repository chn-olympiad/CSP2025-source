#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

string p(string a){//交换 
	string t;
	
	for(int i=a.size()-1;i>=0;i--){
		t+=a[i];
	}
	return t;
	
}
string r(int a){//二进制 
	string s;
	while(a>0){
		s+=a%2+'0';
		a/=2;
	}
	return p(s);
}
int rck(string a){
	a=p(a);
	int k=0,k2=0,h=1;
	while(k2<a.size()){
		k+=(a[k2]-'0')*h;
		h=h*2;
		k2++;
	}
	return k;
}


int x(string a,string b){//xor 
	int r=max(a.size(),b.size());
	string s;
	a=p(a);
	b=p(b);
	if(a.size()> b.size()){
		for(int i=b.size();i<a.size();i++){
			b+='0';
		}
	}else{
		for(int i=a.size();i<b.size();i++){
			a+='0';
		}
	}
	for(int i=0;i<r;i++){
		if(a[i]==b[i]){
			s+='0';
		}else{
			s+='1';
		}
	}
	return rck(p(s));
	
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int o[N];
	o[0]=0;

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int j;
		cin>>j;
		o[i]=x(r(o[i-1]),r(j));
		
	}
	int a=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(x(r(o[i-1]),r(o[j])) == k){
				a++;
				
				i=j;
				
				break;
			}
			
		}
	}
	cout<<a;
	
	return 0;
}
