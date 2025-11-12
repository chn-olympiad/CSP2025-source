#include<bits/stdc++.h>
using namespace std;
string n;
char c;
int m[1000000],p=1,a,b=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n.size();i++){
		c= n[i];
		if('0'<=c && c<='9'){
			m[p] = c - '0';
			p++;
		}
	}
	while(b){
		b=0;
		for(int i=1;i<=p;i++){
			if(m[i]<m[i+1]){
				a = m[i];
				m[i] = m[i+1];
				m[i+1] =a;
				b=1;
			}
		}	
	}
	for(int i=1;i<p;i++){
		cout<<m[i];
	}

	
	

	return 0;
}
