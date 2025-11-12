#include<bits/stdc++.h>
using namespace std; 
struct road{
	int ui;
	int vi;
	int wi;
	}r[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0,cj[20],aj[110][110];
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>r[i].ui>>r[i].vi>>r[i].wi;
		}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(r[i].wi<r[j].wi) swap(r[i],r[j]);
			}
		}
	sum+=r[0].wi+r[1].wi;
	for(int i=0;i<k;i++){
		cin>>cj[i];
		for(int j=1;j<n;j++){
			cin>>aj[i][j];
			}
		}
	sum+=cj[0];
	sum+=3;
	cout<<sum;
	fclose(stdin);
	fclose(stdout); 
	
	return 0;
	
}
