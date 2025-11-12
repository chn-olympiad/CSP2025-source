#include <bits/stdc++.h>
using namespace std;

struct Node{
	int id;
	int s;
}a[105];

int n,m;

bool cmp(Node a,Node b){
	return a.s > b.s;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		a[i].id = i;
		cin>>a[i].s;
	}
	
	sort(a,a+n*m,cmp);
	
	for (int i=0;i<n*m;i++){
		if (a[i].id != 0) continue;
		cout<<i/n+1<<" ";
		if ((i/n)%2){
			cout<<n-(i-i/n*n);
		}else{
			cout<<i-i/n*n+1;
		}
		break;
	}
	
	
	return 0;
}



/*
2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92

3 3
96 95 94 97 98 99 100 93 92

*/













