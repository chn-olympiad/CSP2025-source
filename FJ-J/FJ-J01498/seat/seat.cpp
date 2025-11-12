#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n*m+1);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a.begin()+1,a.end(),cmp);
	int cnt =1; 
	for(int j=1;j<=m;j++){
		if(j&1)
			for(int i=1;i<=n;i++){
				if(a[cnt]==R){
					cout<<j<<" "<<i<<"\n";
					return 0; 
				}else cnt++;
			} 
		else 
			for(int i=n;i>=1;i--){
					if(a[cnt]==R){
						cout<<j<<" "<<i<<"\n";
						return 0; 
					}else cnt++;
				} 
	}
}
