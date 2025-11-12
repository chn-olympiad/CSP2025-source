#include <bits/stdc++.h>
using namespace std;
int n,m,nn,mm,num,se,a[130];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			num+=1;
			cin>>a[num];
		}
	se=a[1];
	sort(a+1,a+num+1,cmp);
	nn=1;
	for(int i=1;i<=num;i++){
		if(nn%2==0){
			mm-=1;
			if(mm==0){
				nn+=1;
				mm=1;
			}
		}
		else{
			mm+=1;
			if(mm==m+1){
				nn+=1;
				mm=m;
			}
		}
//		cout<<a[i]<<endl;
//		cout<<nn<<" "<<mm<<endl;
		if(a[i]==se){
			cout<<nn<<" "<<mm<<endl;
			return 0;
		}
	}
	return 0;
}
