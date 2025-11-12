#include<bits/stdc++.h>
using namespace std;
struct node{
	bool flag;
	int c;
};
node a[15][15];
node num[110];
int n,m;
bool cmp(node a,node b){
	return a.c>b.c;
}
bool find(int n,int m){
	if(a[n][m].flag==1){
		cout<<m<<" "<<n;
		return true;
	}
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>num[i].c;
		if(i==1)num[i].flag=true;
		else num[i].flag=false;
	}
	sort(num+1,num+nm+1,cmp);
//	for(int i=1;i<=nm;i++){
//		cout<<num[i].c<<" ";
//	}
	int cnt=0;
	int f=0;
	for(int j=1;j<=n;j++){
		if(j%2==1){
			for(int i=1;i<=m;i++){
				a[i][j]=num[++cnt];
				if(find(i,j)){
					f=1;
					break;
				}
			}
		}else{
			for(int i=m;i>=1;i--){
				a[i][j]=num[++cnt];
				if(find(i,j)){
					f=1;
					break;
				}
			}
		}
		if(f==1)break;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j].c<<" ";
//		}
//		cout<<endl;
//	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
