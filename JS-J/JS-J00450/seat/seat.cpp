#include<bits/stdc++.h>
using namespace std;
int read();
int n,m,a,s=0;
vector<int> v;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	a=read();
	for(int i=1;i<m*n;i++){
		int r=read();
		if(r>a) s++;
	}
	cout<<s/n+1<<" "<<s%n+1<<endl;
	return 0;
}
int read(){
	char c;
	int f=1,r=0;
	while(!isdigit(c=getchar())){
		if(c=='-') f=-1;
	}
	r=c^48;
	while(isdigit(c=getchar())){
		r=(r*10);
		r+=c^48;
	}
	return r*f;
}
