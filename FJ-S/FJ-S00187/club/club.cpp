#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int my[100005][3];
	int ds[4]={0};
	int r[3]={0};
	int n,t,maxx=0;
	cin>>t;
	while(t--){
		cin>>n;
		maxx=0;
		memset(my,0,sizeof(my));
		memset(ds,0,sizeof(ds));
		for(int i=1;i<=n;i++){
			cin>>my[i][0]>>my[i][1]>>my[i][2];
			for(int j=0;j<3;j++){
				ds[j]=my[i][j];
			}
			sort(ds,ds+3,greater<int>());
			maxx+=ds[0];
		}
		cout<<maxx<<endl;
	}
	return 0;
} 
