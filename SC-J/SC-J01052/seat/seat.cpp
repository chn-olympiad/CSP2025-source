#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105] = {0};
	int n,m;
	cin>>n>>m;
	int num = n*m;
	for(int i=0;i<num;i++){
		cin>>a[i];
	}
	int little_r = a[0];
	int r_id = 0;
	sort(a,a+num,cmp);//成绩越大，越靠前 
	//cout<<a[0];
	for(int i=0;i<num;i++){  //找到小R的名次 
		if(a[i] == little_r){
			r_id = i+1;   //第 i + 1 名 
			break;
		}
	}
	//cout<<r_id<<'\n';
	int x = r_id/n;
	int y = r_id%n;
	//cout<<x<<' '<<y<<'\n';
	if(y != 0)x++;
	if(y == 0)y = n;
	if(x%2 == 0)y = n-y+1;
	if(y>n)y-=n;
	cout<<x<<' '<<y;
	return 0;
} 