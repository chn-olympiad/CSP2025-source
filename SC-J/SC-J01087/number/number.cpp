#include <bits/stdc++.h>
using namespace std;
string s,q[100000],b1;
int he[1000000],a,c,b,he1[10000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; 
	a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]/1==s[i]){
			he1[b]=int(s[i]);
			b+=1;
		}
	}
	c=b;
	b=0;
	for(int i=0;i<c;i++){	
		for(int j=0;j<c;j++){
			q[i]+=he1[j];
		}
	}
	for(int i=0;i<c;i++){	
		if(q[i]>q[i+1]){
			b1=q[i];
		}
	}
	cout<<b1;
	return 0;
}