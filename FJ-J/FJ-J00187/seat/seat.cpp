#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,b[105],p,q,l,k,f;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>b[i];
	l=b[1],k=n*m;
	sort(b+1,b+1+n*m);
	p=1,q=1,f=1;
	while(k){
		a[p][q]=b[k];
		if(b[k]==l){
			cout<<q<<" "<<p;
			break;
		}
		if(f%2==1){
			if(p+1>n)
				++q,++f;
			else
				++p;
		}else{
			if(p-1<=0)
				++q,++f;
			else
				--p;
		}
		--k;
	}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	return 0;
} 
