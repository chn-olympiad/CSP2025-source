#include<bits/stdc++.h>
using namespace std;
long long a[110],b[101][101],s,s1,s2=1,n,m;
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
			s1++;
			b[i][j]=a[s1];
			if(b[i][j]==s){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		}
		else if(i%2==0){
			for(int j=m;j>=1;j--){
			s1++;
			b[i][j]=a[s1];
			if(b[i][j]==s){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		}
		
	}
	return 0;
}