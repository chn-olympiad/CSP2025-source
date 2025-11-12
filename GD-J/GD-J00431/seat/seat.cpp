#include<bits/stdc++.h>
using namespace std;
int n,m,ans,x;
int w[110];
int main(){
	freuse("seat.in","r",stdin);
	freuse("seat.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>w[i];
	}
	int q=w[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(w[j]<=w[i]){
				x=w[j];
				w[j]=w[i];
				w[i]=x;
			}
		}
	}
	int e=1,t=0;
	for(int i=1;i<=n;i+=2){
		for(int j=1;j<=m;j++){
			if(w[e]==q){
				cout<<i<<" "<<j;
				t=1;
				break;
			}
			e++;
		}
		if(t==1){
			break;
		}
		for(int j=m;j>=1;j--){
			if(w[e]==q){
				cout<<i+1<<" "<<j;
				t=1;
				break;
			}
			e++;
		}
		if(t==1){
			break;
		}
	}
	fclose("seat.in",stdout);
	fclose("seat.out",stdout);
	return 0;
}
