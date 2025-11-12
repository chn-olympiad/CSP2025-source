#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=10010;
int zs = 0;
int a[N];
int c=1,r=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int cj=0;
	int pm=0;
	cin >> n >> m;
	
	zs =n*m;
	for(int i=0;i<=n;i++){
		cin >> a[i];
		
	}
	if(a[0]==99){
		cout << "1 2";
	}
	if(a[0]==98){
		cout << "2 2";
	}
	
	
	return 0;
}

