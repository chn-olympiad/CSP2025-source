#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
using namespace std;
int seat[20][20];
int n,m,posR=0,R1;
struct node{
	int sc;
	int pos;
}s[(int)(2e5+5)];

bool cmp(node x,node y){
	return x.sc>y.sc;
}

void fun(){
	if(n==1){
		cout<<posR<<" "<<1;
		return;
	}
	int nx=1,ny=1,num=1/*num为第s[num]学生*/;
	while(nx<=m){
		while(ny<=n){
			
			//cout<<"第"<<nx<<"行，第"<<ny<<"列："<<"第"<<num<<"个\n" ;
			if(num==posR){
				cout<<nx<<" "<<ny<<endl;
				return;
			}
			ny++;
			num++;
			
		}
		ny--;
		nx++;
		while(ny>=1){
			
			//cout<<"第"<<nx<<"行，第"<<ny<<"列："<<"第"<<num<<"个\n" ;
			if(num==posR){
				cout<<nx<<" "<<ny<<endl;
				return;
			}ny--;
			num++;
		}
		ny++;
		nx++;
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].sc;
		s[i].pos=i;
	} 
	R1=s[1].sc;
	sort(s+1,s+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i].sc == R1){
			posR=i;
		}
	} 
	fun();
	return 0;
}
