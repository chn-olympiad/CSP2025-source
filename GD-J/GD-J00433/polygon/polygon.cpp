#include<bits/stdc++.h>
using namespace std;
int n,a[50005],Ans=0,S=0,ma=0;
bool d[50005];
int f(int L,int l,int p,int mm){
	if(l<3){
		return 0;
	}
	int ANS=0,mx=0,k=0;
	if(L>mm*2){
		cout<<L<<" "<<mm<<" "<<p<<endl;
		ANS++;
	}
	for(int i=p;i<n;i++){
		if(!d[i]){
			d[i]=true;
			if(a[i]==mm){
				for(int j=0;j<n;j++){
					if(!d[j] && a[j]!=mm){
						mx=max(mx,a[j]);
					}
				}
				ANS+=f(L-a[i],l-1,i+1,mx);
			}else{
				mx=max(mx,a[i]);
				ANS+=f(L-a[i],l-1,i+1,mm);
			} 
			d[i]=false;
		}
	}
	return ANS;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		S+=a[i];
		ma=max(ma,a[i]);
	}
	cout<<f(S,n,0,ma);
	return 0;
} 
