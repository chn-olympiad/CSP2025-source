#include<bits/stdc++.h>
using namespace std;

int sm,ks,yhz[500010],zs;
bool fyhz[500010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>sm>>ks;
	
	for(int i=1;i<=sm;i++){
		cin>>yhz[i];
		
		if(yhz[i]==ks){
			zs++;
			fyhz[i]=true;
		}
	}
	
	for(int i=1;i<=sm;i++){
		if(!fyhz[i]){
			int gj=yhz[i],qd=0;
			
			for(int j=i+1;j<=sm && !fyhz[j];j++){
				gj^=yhz[j];
				
				if(gj==ks){
					qd=j;
					zs++;
					
					break;
				}
			}
			
			for(int j=i;j<=qd;j++){
				fyhz[j]=true;
			}
		}
	}
	
	cout<<zs;
	
	return 0;
}
