#include<bits/stdc++.h>
using namespace std;

int map_1[12][12];
int a[102];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;//行  列
	cin>>n>>m;
	int people_number=n*m;//人数 
	for(int i=1;i<=people_number;i++){
		cin>>a[i];
	}
	int fen=a[1];//小明分数
	sort(a+1,a+people_number+1,cmp);
	
	int jilu;
	for(int i=1;i<=people_number;i++){
		if(a[i]==fen){
			jilu=i;
			break;
		}
	}
	
	int x,y;
	if(jilu%n==0){
		y=jilu/n;
		if(y%2==0){
			x=1;
			cout<<y<<" "<<x;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else{
			x=n;
			cout<<y<<" "<<x;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}else{
		int yushu=jilu%n;
		y=jilu/n+1;
		if(y%2==0){
			x=n-yushu+1;
			cout<<y<<" "<<x;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}else{
			x=yushu;
			cout<<y<<" "<<x;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
