#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005],s = 0;
void dfs(int id,int v,int ma,int i){
	if(id > n){
		return ;
	}
	if(i >= 3 && v > ma * 2){
		s++;
	}
	dfs(id + 1,v + a[id],max(ma,a[id]),i + 1);
	dfs(id + 1,v,ma,i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == 3){
		if(a[1] + a[2] + a[3] > max(a[1],(a[2],a[3]) * 2) ){
			cout << 1;
		}else{
			cout << 0;
		}
		return 0;
	}
	dfs(1,0,a[1],0);
	cout << s;
	return 0;
} 
