#include<bits/stdc++.h>
//输出为 列 行 
using namespace std;
int v[15][15];
priority_queue<int>q;
int n,m,goal;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n行m列 
	cin>>goal;
	q.push(goal);
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		q.push(a);
	}
	for(int j=1;j<=m;j++){
		
			
			if(j%2){
				for(int i=1;i<=n;i++){
					v[j][i]=q.top();
					q.pop();
					if(v[j][i]==goal){
						cout<<j<<' '<<i;
						return 0;
					}
				}
			}else{
				for(int k=n;k>=1;k--){
					v[j][k]=q.top();
					q.pop();
					if(v[j][k]==goal){
						cout<<j<<' '<<k;
						return 0;
					}
					
				}
			}
		}
	
	return 0;
}
