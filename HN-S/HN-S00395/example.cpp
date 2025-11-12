#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int ans = 0;
	double qwq = clock();
	for(int i=1;i<=1000000000;i++){
		if(i%2==0){
			ans+=3;
		}
	}
	double awa = (clock()-qwq)/CLOCKS_PER_SEC;
	cout<<1000000000/awa<<endl;
	//i love you
	return 0;
}
