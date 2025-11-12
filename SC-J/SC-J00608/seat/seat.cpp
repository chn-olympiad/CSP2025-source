#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8;
string s;
int st[N],num[N],ans[N];
int main(){
	
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a=0,m,n,grade;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			int x=i*m+j;
			cin>>num[x];
			if(i==0&&j==1){
				grade=num[x];
			}
		}
	}
	int l=m*n;
	sort(num+1,num+(m*n)+1);
	
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			int x=i*m+j;
			int y=(x%n);
			int z=(x/n);
			ans[l-(y+z*n)+1]=num[x];
		}
	}
	for(int j=1;j<=(m*n);j++){
		
		if(ans[j]==grade){
			
			int y=((j-1)%n)+1;
			int z=((j-1)/n)+1;
			if((z%2)==0){
				cout<<z<<" "<<n-y+1;
			}else{
				cout<<z<<" "<<y;
			}
			
		}
	}
	
	return 0;
} 