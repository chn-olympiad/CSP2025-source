#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long mx;
long long df[200005];
long long a[200005][5];
void dfs(int x,int x1,int x2,int x3){

	if(x==m&&x1+x2+x3==m){
		//cout<<xx[1]<<" "<<xx[2]<<" "<<xx[3]<<endl;
		//cout<<x1<<" "<<x2<<" "<<x3<<endl; 
		return;
	}
	
	for(int i=1;i<=m;i++){
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			if(x1<(m/2)){
				//cout<<m<<endl;
				df[i]=df[i-1]+a[i][1];
			
			//	cout<<a[i][1]<<" ";
				dfs(x+1,x1+1,x2,x3);
	
			}
		}
		if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			if(x2<(m/2)){
			//	cout<<m<<endl;
				df[i]=df[i-1]+a[i][2];
			//	cout<<a[i][2]<<" ";
				dfs(x+1,x1,x2+1,x3);
			}
		}
		if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
			if(x3<(m/2)){
				//cout<<m<<endl;
				df[i]=df[i-1]+a[i][3];
				
			//	cout<<a[i][3]<<" ";
				dfs(x+1,x1,x2,x3+1);
				
			}
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		
		for(int j=1;j<=m;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		} 
		dfs(0,0,0,0);
		mx=0;
	//	cout<<endl;
		for(int j=1;j<=m;j++){
		//	if(xx[j]<=(m/2)){
				mx=max(mx,df[j]);
				//cout<<xx[j]<<" ";
				//out<<df[j]<<endl; 
		//	}
		}
	//	cout<<endl;
		cout<<mx<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
