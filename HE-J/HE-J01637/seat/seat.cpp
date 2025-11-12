//注意到n<=10,m<=10，模拟
#include<bits/stdc++.h>
using namespace std;
int a[20000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int posx=1,posy=1;//
	int ans=a[1];//成绩
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		//cout<<posx<<" "<<posy<<"\n";
		if(ans==a[i]){
			cout<<posx<<" "<<posy;
			return 0;
		}
		if(i%n==0){
			posx++;
			if(posx&1)posy=1;
			else posy=n;
		}
		else {
			if(posx&1)posy++;
			else posy--;
		}
	}
	return 0;
}
