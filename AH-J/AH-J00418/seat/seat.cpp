#include <bits/stdc++.h>
using namespace std;
//priority_queue<int> q;
//priority_queue<int> q;
int a[105];
int b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int tmp; 
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			tmp=i;
			break;
		}
	}
	if(tmp%n){
		cout<<tmp/n+1<<" ";
	}
	else cout<<tmp/n<<" ";
	if(int(ceil(tmp*1.0/n))%2==1){
		if(tmp%n==0){
			cout<<n;
		}
		else{
			cout<<tmp%n;
		}
	}else{
		cout<<n-tmp%n+1;
	}
	return 0;
}
