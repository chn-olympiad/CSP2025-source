#include<bits/stdc++.h>
using namespace std;
int a,b,c,d[15][15];
bool t;
priority_queue<int> tp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b>>c;
	tp.push(c);
	for(int i=1;i<=a*b-1;i++){
		int p;
		cin>>p;
		tp.push(p);
	}
	for(int i=1;i<=b;i++){
		if(t){
			for(int j=a;j>0;j--){
				d[j][i]=tp.top();
				tp.pop();
				t=false;
			}
		}
		else{
			for(int j=1;j<=a;j++){
				d[j][i]=tp.top();
				tp.pop();
				t=true;
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(d[i][j]==c){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
