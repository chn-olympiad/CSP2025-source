#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n,q=0;
void dfs(int wz,int z,int zdz,int cd){
	if(z>zdz*2&&cd>=3){
		q++;
//		cout<<"--"<<endl<<wz<<' '<<z<<' '<<zdz<<' '<<cd<<endl<<"--"<<endl;
	}
	if(wz>n-1){
		return;
	}
//	cout<<wz<<' '<<z<<' '<<zdz<<' '<<cd<<endl;
	for(int i=1;wz+i<n;i++){
		if(a[wz+i]>zdz){
			dfs(wz+i,z+a[wz+i],a[wz+i],cd+1);
		}else{
			dfs(wz+i,z+a[wz+i],zdz,cd+1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i+2<n;i++){
		dfs(i,a[i],a[i],1);
	}
	cout<<q%998244353<<endl;
	return 0;
}
