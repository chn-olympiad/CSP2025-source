#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ren,me;
	int lst[10000];
	cin>>n>>m;
	ren = n*m;
	for(int i=0;i<ren;i++){
		int x;
		cin>>x;
		lst[i]=x;
	}
	me = lst[0];
	for(int i=0;i<=ren;++i){
		if(lst[i]<lst[i+1]){
			int n = lst[i];
			lst[i]=lst[i+1];
			lst[i+1]=n;
		}
	}
	int hao;
	for(int i=0;i<=ren;++i){
		if(lst[i]==me){
			hao=i+1;
		}
	}
	int c,r;
	if(hao<=n){
		c=1;
		r=hao;
	} 
	if(hao>n){
		c=hao/n+1;
		r=n-(hao%n-1);
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

