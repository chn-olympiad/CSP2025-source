#include<bits/stdc++.h>
using namespace std;
int n,m;
int nm;
int xiaor,wr;
int a[110];

bool cmp(int a,int b){
	return a>b;
}
void st(int n, int m, int wrcj){
	int q = (wrcj / n) +1;
	if(wrcj%n == 0)q--;
	int w = wrcj - ((q-1)*n);
	if(q%2==0) w = n - w + 1;
	cout<<q<<' '<<w;
}

int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm = n*m;
	for(int i = 1; i <= nm; i++){
		cin>>a[i]; 
	}
	xiaor = a[1];
	sort(a+1,a+1+nm,cmp);
	for(int i = 1; i<=nm;i++){
		if(a[i] == xiaor){
			wr = i;
			break;
		}
	}
	st(n,m,wr);
	return 0;
} 
