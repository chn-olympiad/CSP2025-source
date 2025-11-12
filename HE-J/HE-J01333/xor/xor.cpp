#include<bits/stdc++.h>
using namespace std;
int p(int o){
	int a=0,e=1,w;
	w=o;
	while(o>0){
		a=o%2+a*10;
		o/=2;
	}
	while(w>0){
		if(w%2==0)e*=10;
		else break;
		w/=2;
	}
	return a*e;
}
int u(int o,int z){
	int a[21],b[21],i=1,j=1,e,r=21,t=0;
	if(z>o)swap(o,z);
	e=o;
	for(int i=1;i<=21;i++){
		a[i]=0;
	}
	for(int i=1;i<=21;i++){
		b[i]=0;
	}
	while(o>0){
		a[i]=o%10;
		o/=10;
		i++;
	}
	while(z>0){
		b[j]=z%10;
		z/=10;
		j++;
	}
	for(int i=1;i<=21;i++){
		cout<<a[i];
	}
	cout<<endl;
	for(int i=1;i<=21;i++){
		cout<<b[i];
	}
	cout<<endl;
	for(int s=1;s<=e/10;s++){
		if(a[s]!=b[s]||b[s]!=a[s]){
			int g=1;
			for(int c=s-1;c>=0;c--){
				g*=2;
			}
			t+=g;
		}
		cout<<t<<endl;
	}
	return t;
}
int main(){
    int q[500001],n,k;
	freopen("xor.in","in",stdin);
	freopen("xor.out","out",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>q[i];
	}
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		int w=i,e=q[i];
    		while(w<=j){
    			
			}
    	}
	}
    cin>>n>>k;
    int d=p(n),f=p(k);
    cout<<d<<endl<<f<<endl;
    cout<<u(d,f);
    return 0;
}
