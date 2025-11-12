#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> op;
int a[100005];
void fun(int index,int sum,int cnt){
	int y = sum|a[index];
	if(y == k){
		fun(index+1,0,cnt+1);
		fun(index+1,y,cnt);
	}else if(index == n){
		op.push_back(cnt);
		return;
	}else{
		fun(index+1,0,cnt);
		fun(index+1,y,cnt);
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	fun(0,0,0);
	int max_op = 0;
	for(int i = 0;i < op.size();i++){
		max_op = max(op[i],max_op);
	}
	cout<<max_op;
	return 0;
}
