#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s=0,des;
	cin>>n>>m;
	vector<int>a(n*m+1);
	for(int i=1;i<=n*m;i++) cin>>a[i];
	des=a[1];
	sort(a.begin()+1,a.end(),cmp);
	
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				s++;
				
				if(a[s]==des){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				s++;
				
				if(a[s]==des){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		
	}
	return 0;
}
//2 2 99 100 97 98
//2 2 98 99 100 97
//3 3 94 95 96 97 98 99 100 93 92
