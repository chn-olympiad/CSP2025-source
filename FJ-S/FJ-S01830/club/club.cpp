#include<bits/stdc++.h>
using namespace std;
int t,l,ans;
const int N=1e5+5;
int n[N]; 
int b[N];
int c[N];
int x[20004],y[20004],z[20004];
void dfs(){
	int m=n[ans];
	sort(x+1,x+1+m);
	for(int i=l+1;i<=m;i++){
		b[ans]+=x[i];
	}	
}
void cz(){
	int m=n[ans];
	sort(x+1,x+1+m);
	sort(y+1,y+1+m);
	for(int i=l+1;i<=m;i++){
		b[ans]+=x[i];
	}
	for(int i=l+1;i<=m;i++){
		b[ans]+=y[i];
	}	
}
void zy(){
	for(int i=1;i<=n[ans];i++){
		c[i]=max(max(x[i],y[i]),z[i]);
	}
	for(int i=1;i<=n[ans];i++){
		b[ans]+=c[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans++;
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>x[j]>>y[j]>>z[j];
		}
		l=n[i]/2;
		for(int j=1;j<=n[ans];j++){
		int s=0;
		if(z[j]!=0){
			zy();
			break;
		}
		if(y[j]!=0){
			cz();
			break;
		}
		if(j==n[ans]){
			if(s==0){
				dfs();
			}
		}
	}	
	
	}
	for(int i=1;i<=ans;i++){
		cout<<b[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
