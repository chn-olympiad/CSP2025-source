#include<bits/stdc++.h>
using namespace std;
const int MAX=5001;
int n;
int l[MAX];
bool used[MAX];
int pd[MAX],pdr;
bool pdi(){
	if(pdr<3){
		return 0;
	}
	int maxl=0,andd=0;
	for(int i=1;i<=pdr;i++){
		maxl=max(maxl,pd[i]);
		andd+=pd[i];
	}
	return (andd>(maxl*2));
}
/*int d(int x){
	int ans=0;
	for(int i=1;i<n;i++){
		if(!used[i]){
			pd[x]=l[i];
			ans+=pd(x);
			d()
		}
	}
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	if(n=3){
		if((max(max(l[1],l[2]),l[3])*2)<(l[1]+l[2]+l[3])){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else{
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
