#include<bits/stdc++.h>
using namespace std;
int x[100000][3];
int q,w,e;
int fdsa(int a,int b,int c){
	if(a==c){
		return b;
	}else{
		int d=c/2;
		int a1=0,a2=0,a3=0;
		if(q<d){
			q++;
			a1=fdsa(a+1,b+x[a][0],c);
			q--;
		}
		if(w<d){
			w++;
			a2=fdsa(a+1,b+x[a][1],c);
			w--; 
		}
		if(e<d){
			e++;
			a3=fdsa(a+1,b+x[a][2],c);
			e--;
		}
		
		return(max(max(a1,a2),a3));
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		q=0;
		w=0;
		e=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>x[j][k];
			}
		}
		int ans=0;
		ans=fdsa(0,0,n);
		cout<<ans<<"\n";
	}
	return 0;
}
