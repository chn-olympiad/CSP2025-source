#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int fen;
	int num;
}a[101];
bool cmp(stu b,stu c){
	return b.fen>c.fen;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c++;
			cin>>a[c].fen;
			a[c].num=c;
		}
	}
	sort(a+1,a+c+1,cmp);
	for(int i=0;i<c;i++){
		if(a[i+1].num==1){
			if(i%(n*2)<n){
				cout<<i/n+1<<" "<<i%n+1;
			}else{
				cout<<i/n+1<<" "<<n-i%n;
			}
			return 0;
		} 
	}
	return 0;
} 