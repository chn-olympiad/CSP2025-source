#include<bits/stdc++.h>
using namespace std;
int n,m,sum,p,k;
struct ui{
	int id;
	int num;
}a[105];
inline bool cmp(ui bb,ui cc){
	return bb.num>cc.num;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i].num;
		a[i].id=i; 
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i].id==1){
			p=i;
			break;
		}
	}
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				k++;
				if(k==p){
					cout<<j<<" "<<i;
					break;
				}
			}	
		}
		else{
			for(int i=n;i>=1;i--){
				k++;
				if(k==p){
					cout<<j<<" "<<i;
					break;
				}
			}	
		}
			
	}
	return 0;
}