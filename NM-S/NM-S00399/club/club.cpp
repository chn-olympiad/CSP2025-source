#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[100005][5];


int c(){
	int x[5][100005]={0};
	int s=0,sa=0;
	for(int i = 1;i <= n;i++){
		x[1][1]=1002;
		s=max(a[i][1],a[i][2]);
		s=max(a[i][3],s);
		sa+=s;
		
	}
	
	

	return sa;
};

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i = 1;i <= t;i++){
		cin>>n;
		for(int j = 1;j <= n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		cout<<c()<<endl;
		
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
