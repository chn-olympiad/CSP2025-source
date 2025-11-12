#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ2.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,p=0,b;
	cin>>n>>m;
	int si1[n];
	int si;	
	cin>>si;
	int ci[n],ci1[n];
	for(int i=0;i<n;i++){
		b=si%10;
		si1[i]=b;
		}
	for(int i=0;i<n;i++){
		cin>>ci[i];
		}
		for(int i=0;i<n;i++){
			if(si1[i]==1){
				p++;
				for(int j=0;j<n;j++){
				ci1[j]++;	
			}
		}
			
				if(si1[i]==0){
				for(int j=0;j<n;j++){
				ci1[j]++;	
				}
		}
			}
			cout<<(p-1);
			
	}
