#include<bits/stdc++.h>
using namespace std;
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int inlet[m*n];
	for(int i=1;i<=m*n;i++){
		cin>>inlet[i];
	}
	int ming=inlet[1];
	sort(inlet+1,inlet+1+(m*n),cmd);
	int pos1,pos2,pos3;
	for(int i=1;i<=m*n;i++){
		if(ming==inlet[i]){
			pos1=i;
		}
	}
	//cout<<pos1<<" ";
	pos1%n==0?pos2=pos1/n:pos2=floor(pos1/n)+1;
	cout<<pos2<<" ";
	pos1<=n?pos3=pos1:pos1%n==0?pos3=n:pos2%2!=0?pos3=pos1%n:pos3=n+1-pos1%n;
	cout<<pos3;
	return 0;
}