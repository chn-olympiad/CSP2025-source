#include<bits/stdc++.h> 
using namespace std;
int n,m,h,maxx=0,t[10030][4],z[10030],k[10030];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>h;
	while(h--){
		int s,pana=0,panb=0;
		cin>>s;
		for(int i=0;i<=s;i++){
			cin>>t[i][0]>>t[i][1]>>t[i][2];
			if(t[i][1]!=0){
				pana=1;
			} else if(t[i][2]!=0){
				pana=1;
				panb=1;
			}
			z[i]=t[i][0];
			k[i]=t[i][1];
		}
		if(pana==0){
			sort(z,z+s);
			int an=0;
			for(int i=s-1;i>s/2;i--){
				an+=z[i];
			}cout<<an;
		}
		else if(panb==0){
			int an=0;
			for(int i=s-1;i>s/2;i--){
				an+=max(k[i],z[i]);
			}
		}
	}
	return 0;
}
