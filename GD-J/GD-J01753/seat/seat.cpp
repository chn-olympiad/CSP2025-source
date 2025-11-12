#include<bits/stdc++.h>
using namespace std;
int a[114514];
int n,m,p,id; 
int c,r,mood;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++){
		cin>>a[i];
	}
	p = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == p){
			id = i;
			break;
		}
	}
	if(id % n == 0){
		c = id / n;
	}else{
		c = id / n + 1;
	}
	cout<<c<<" ";
	if(id <= n){
		mood = id;
	}else{
		mood = id % n;
	}
	if(c % 2 == 0){
		r = n - mood + 1;
	}else{
		r = mood;
	}
	cout<<r<<endl;
	return 0;
}

