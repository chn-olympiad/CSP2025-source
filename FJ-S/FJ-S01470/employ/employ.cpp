#include<bits/stdc++.h>
using namespace std;
int nn,m,ans,qp,t;
string z;
int c[1005];
int n[1005];
//~QWQ~
int main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>nn>>m>>z;
	if(nn==m){
		int awa=1;
		for(int i=1;i<=nn;i++){
			awa*=i;
		}
		cout<<awa;
		return 0;
	}
	for(int i=0;i<nn;i++){
		cin>>c[i];
	}
	sort(c,c+nn);
	for(int i=0;i<nn;i++){
		if(z[i]=='0'){
			t++;
		}
		for(int j=0;j<nn;j++){
			if(c[j]==t){
				n[j]=1;
			}
		}
	}
	for(int i=0;i<nn;i++){
		if(n[i]==1){
			for(int j=i+1;j<nn;j++){
				if(n[j]==1){
					if(c[i]<c[j]){
						int pq;
						pq=c[i];
						c[i]=c[j];
						c[j]=pq;
						n[i]=0;
					}
				}
			}
		}
	}
	int cnt=0,cny=0;
	//cout<<cnt<<endl;
	for(int i=0;i<nn;i++){
		if(n[i]==0){
			cnt++;
			for(int j=0;j<nn;j++){
				if(c[j]==c[j+1]&&n[j]==0&&n[j+1]==0){
					cnt--;
				}
			}
		}
		if(n[i]==1){
			cny++;
			for(int j=0;j<nn;j++){
				if(c[j]==c[j+1]&&n[j]==1&&n[j+1]==1){
					cny--;
				}
			}
		}
	}
	//for(int i=0;i<nn;i++){
	//	cout<<n[i]<<" ";
	//}
	//cout<<endl;
	//cout<<cnt<<" "<<cny<<endl; 
	ans+=cnt*cnt+cny*cny;
	cout<<ans;
	return 0;
}
