#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	long long u=0;
	long long c=0;
	long long e=a.size();
	int b[e];
	int q[e]={0};
	int s=0;
	for(int i=0;i<e;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[c]=a[i]-'0';
			u++;
			c++;
			}
		}
		int o=e;
		while(o>0){
			int d=0;
			for(int i=0;i<c;i++){	
		if(b[i]>q[s]){
			q[s]=b[i];
	}
		}
		for(int i=0;i<c;i++){			
		if(b[i]==q[s]&&d==0){
			b[i]=0;
			d++;
	}}
	o--;
	s++;
		}
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=0;i<u;i++){cout<<q[i];}
	return 0;
	}
