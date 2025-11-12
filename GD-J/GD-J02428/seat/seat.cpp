#include<bits/stdc++.h>
using namespace std;
struct Node{
	int id=0;
	int score;
}a[10001];
bool cmp(Node a,Node b){
	return a.score>b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].id=i;
		cin>>a[i].score;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			int x=i/n;
			if(x%2){
				if(i%n==0)cout<<x;
				else cout<<x+1;
				cout<<" ";
				if(i%n==0)cout<<m;
				else cout<<m+1-(i%n);
				
			}
			else{
				if(i%n==0)cout<<x;
				else cout<<x+1;
				cout<<" ";
				if(i%n==0)cout<<1;
				else cout<<i%n;
			}
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
