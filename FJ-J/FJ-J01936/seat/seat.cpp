#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m,R;
	int stu[110];
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>stu[i];
	R=stu[1];
	sort(stu+1,stu+1+n*m,cmp);
	for (int i=0;i<m;i++){
		for (int j=1;j<=n;j++){
			if(stu[i*n+j]==R){
				cout<<i+1<<" "<<(i%2==0?j:n-j+1);
				return 0; 
			}
		}
	}
	
	return 0;
}
