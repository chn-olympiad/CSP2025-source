#include<bits/stdc++.h>
using namespace std;
int c[100000];
int b[100000];
int main(){
	freopen("employs.in","r",stdin);
	freopen("employs.out","w",stdout);
	int n;
	int d = 0;
	int f= 0;
	cin>>n;
	int m;
	cin>>m;
	string r;
	cin>>r;
	//for(int i=1;i<=n;i++){
	//	b[i] = r%(n-i)*10;
	//	r%i*10;
	//}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(i >= c[i]){
			if(b[i] == 1){
				c[i] == 0;

				d += 1;
			}
		}
	}

	cout<<d;



	return 0;
}
