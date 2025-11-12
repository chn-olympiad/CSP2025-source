#include<bits/stdc++.h>
using namespace std;
int n,m,sl,c[510],sum,zds,man;
string sh;
void sjh(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sl=0,man=0;
			if(c[i]!=c[j]){
				swap(c[i],c[j]);
				for(int j=1;j<=n;j++){
					if(sh[j]=='1'&&c[j]>=sl){
						sum++;
					}
					else{
						sl++;
					}
				}
				if(sum==m){
					zds++;
				}
				swap(c[i],c[j]);
			}
			
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>sh;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int j=1;j<=n;j++){
		if(sh[j]=='1'&&c[j]>=sl){
			sum++;
		}
		else{
			sl++;
		}
	}
	if(sum==m){
		zds++;
	}
	sjh();
	cout<<zds;
	return 0;
} 
