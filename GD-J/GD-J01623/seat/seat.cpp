#include<bits/stdc++.h>
using namespace std;
int m,n,a[110];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	//std::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>m>>n;
	int g=m*n;
	for(int i =1;i<=g;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+g+1,cmp);
	int i =1;
	for(i =1;r!=a[i];i++);
	int j =i;
	int xs=0;
	while(i>n){
		i-=n;
		if(i==0)i=1;
		xs++;
	}
	xs++;
	if(xs==0)xs=1;
	if(xs%2==0) cout<<xs<<' '<<m-(j-xs*n+n)+1;
	else if(xs%2!=0) cout<<xs<<' '<<j-xs*n+n;
	
}
