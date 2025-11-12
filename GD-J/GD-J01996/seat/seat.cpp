#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;

const int N=150;
int n,m;
int a[150];
int x=1,y=0;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		y++;
		if(a[i]==t){
			cout<<x<<" "<<y<<"\n";
			return 0;
		}
		if(y==m){
			y=0;
			x++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

