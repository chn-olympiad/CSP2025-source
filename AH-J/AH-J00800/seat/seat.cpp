#include<bits/stdc++.h>
using namespace std;
long long maze[110],n,m,a,flag=0;
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	maze[1]=a;
	for(int i=2;i<=n*m;i++){
		cin>>maze[i];
	}
	sort(maze+1,maze+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(maze[i]==a){
			flag=i;
		}
	}
	int x=flag/n;
	if(flag%n){
		x++;
	}
	cout<<x<<' ';
	if(x%2){
		if(flag%m){
			cout<<flag%m;
		}
		else{
			cout<<n;
		}
	}else{
		cout<<n-(flag%n)+1;
	}
	cout << endl<<x<<' '<<flag;
	return 0;
}
