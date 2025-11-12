#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],marks;
int xu[1001][1001];
int s;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}	
	marks=a[0];
	sort(a,a+m*n,cmp);
		for(int i=0;i<m;i++){
			if(i%2==0){
				for(int j=0;j<n;j++){
					xu[j][i]=a[s];
					s++;
				}
			}else{
				for(int j=n-1;j>=0;j--){
					xu[j][i]=a[s];
					s++;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(xu[i][j]==marks){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
				}
		}
	return 0;
}
