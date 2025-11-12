#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		cnt+=a[i];
	}
	if(n<3){
		cout<<"0"<<endl;
	}else{
		if(cnt>maxn*2){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

// 100+100+15+12=227pts
// What a vegetable OIer I am! 
