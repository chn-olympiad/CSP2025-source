#include<bits/stdc++.h>
using namespace std;
int read();
long long n,k;
long long maxn=0;
vector<long long> v;
int work(int x,int y);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();
	k=read();
	for(int i=0;i<n;i++){
		v.push_back(read());
	}
	for(int i=0;i<n;i++){
		int x=i;
		int s=0;
		for(int j=i;j<n;j++){
			if(work(x,j)==k){
				s++;
				//cout<<x<<" "<<j<<" "<<s<<endl;
				x=j+1;
			}
		}
		if(s>=maxn) maxn=s;
	}
	cout<<maxn<<endl;
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
int work(int x,int y){
	int r=0;
	for(int i=x;i<=y;i++){
		r=r^v[i];
	}
	return r;
}
