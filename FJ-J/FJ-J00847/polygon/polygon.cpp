#include<bits/stdc++.h>
using namespace std;
const int MDO=998244353;
int n,l[5005],ans;
struct node{
	int step;
	int mx;
	int num;
	int tal; 
};
queue <node> qu;
void BFS(){
	while(!qu.empty()){
		node x=qu.front();
		qu.pop();
		if(x.step>=3&&x.tal>2*x.mx){ans++;ans%=MDO;}
		for(int i=x.num+1;i<=n;i++){
			qu.push((node){x.step+1,max(x.mx,l[i]),i,l[i]+x.tal});
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> l[i];
	}
	for(int i=1;i<=n;i++){
		qu.push((node){1,l[i],i,l[i]});
		BFS();
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}









