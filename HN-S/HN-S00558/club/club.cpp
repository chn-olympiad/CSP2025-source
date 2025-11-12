#include<bits/stdc++.h>
using namespace std;
int a[3];
int b[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f=0;
		int all[9]={0};
		for (int x=1;x<=3;x++){
			cin>>a[x];
		}
		for (int x=1;x<=3;x++){
			cin>>b[x];
		}
		int s=1;
		for (int x=1;x<=3;x++){
			for (int y=1;y<=3;y++){
				if(x!=y){
					all[s]=a[x]+b[y];
					f=max(f,all[s]);
					s++;
			}
			} 
		}
		cout<<f;
		cout<<endl;
	}
	return 0;
} 
