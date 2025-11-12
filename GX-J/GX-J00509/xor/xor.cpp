#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a,b,c,d,e,f,g;
	vector<long> k,qi,mo,ji;
	cin>>a>>b;
	for(int x=0;x<a;x++){
		cin>>c;
		k.push_back(c);
	}
	for(int x=0;x<a;x++){
		d=k[x];
		for(int u=x+1;u<a;x++){
			c=k[u];
			d=d^c;
			if(d==b){
				qi.push_back(x);
				mo.push_back(x);
				break;
			}
		}
	}
	e=qi.size();
	for(int x=0;x<e;x++){
		f=k[x];
		if(f==b){
			ji.push_back(x);
			continue;
		}
		for(int u=x+1;u<e;u++){
			f=qi[u];
			g=qi[x];
			if(g<=f){
				g=mo[x];
				if(g>=f){
					ji.push_back(x);
				}
			}
		}
	}
	a=qi.size();
	b=ji.size();
	a=a-b;
	cout<<a;
	
	
	
	return 0;
	}
