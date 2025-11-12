#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cmp(int x,int y){
	return x > y;
}
int fi_1(int p){
	for(int i = 0;i < n*m;i++){
		if(a[i] == p){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len = n*m;
	for(int i = 0;i < len;i++){
		cin>>a[i];
	}
	int uo = a[0];
	sort(a,a+len-1,cmp);
	int index = fi_1(uo);
	int x=1,y=1;
	int num = 0;
	while(true){
		//cout<<index<<' '<<num<<'\n';
		if(index >= m){
			index-=m;
			x++;
			x%=m+1;
		}else if(index < m){
			if(num){
				y = m - index;
			}else{
				y = index+1;
			}
			break;
		}
		num=(num+1)%2;
	}
	cout<<x<<' '<<y;
	return 0;
}
