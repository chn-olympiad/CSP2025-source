#include<bits/stdc++.h>
using namespace std;
struct sut{
	int a1;
	int a2;
	int a3;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int a=0;
		int n;
		cin>>n;
		sut h[n];
		int g[3]={0,0,0};
		for(int i=1;i<=n;i++){
			cin>>h[i].a1;
			cin>>h[i].a2;
			cin>>h[i].a3;
			if(h[i].a1>h[i].a2>h[i].a3){
				if(n/2>=g[0]){
					a+=h[i].a1;
					g[0]++;
				}else if(n/2>=g[1]){
					a+=h[i].a2;
					g[1]++;
				}else if(n/2>=g[2]){
					a+=h[i].a3;
					g[2]++;
				}
				
			}else if(h[i].a3>h[i].a2>h[i].a1){
				if(n/2>=g[0]){
					a+=h[i].a3;
					g[0]++;
				}else if(n/2>=g[1]){
					a+=h[i].a2;
					g[1]++;
				}else if(n/2>=g[2]){
					a+=h[i].a1;
					g[2]++;
				}
			}else if(h[i].a2>h[i].a1>h[i].a3){
				if(n/2>=g[0]){
					a+=h[i].a2;
					g[0]++;
				}else if(n/2>=g[1]){
					a+=h[i].a1;
					g[1]++;
				}else if(n/2>=g[2]){
					a+=h[i].a3;
					g[2]++;
				}
			}else if(h[i].a1>h[i].a3>h[i].a2){
				if(n/2>=g[0]){
					a+=h[i].a1;
					g[0]++;
				}else if(n/2>=g[1]){
					a+=h[i].a3;
					g[1]++;
				}else if(n/2>=g[2]){
					a+=h[i].a2;
					g[2]++;
				}
			}else if(h[i].a3>h[i].a1>h[i].a2){
				if(n/2>=g[0]){
					a+=h[i].a3;
					g[0]++;
				}else if(n/2>=g[1]){
					a+=h[i].a1;
					g[1]++;
				}else if(n/2>=g[2]){
					a+=h[i].a2;
					g[2]++;
				}
			}else if(h[i].a2>h[i].a3>h[i].a1){
				if(n/2>=g[0]){
					a+=h[i].a2;
					g[0]++;
				}else if(n/2>=g[1]){
					a+=h[i].a3;
					g[1]++;
				}else if(n/2>=g[2]){
					a+=h[i].a1;
					g[2]++;
				}
			}
		}
		cout<<a<<endl;
	}
	return 0;
}
