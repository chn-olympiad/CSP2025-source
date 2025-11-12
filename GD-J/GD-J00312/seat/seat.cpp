#include<bits/stdc++.h>
using namespace std;
int n,m;
int sr,cnt;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> sr;
	for(int i=1;i<n*m;i++){
		int s;
		cin >> s;
		if(s>sr) cnt++;
	}
	c=cnt/n+1;
	cnt++;
	if(c%2){
		if(!cnt%n) r=n;
		else r=cnt%n;
	}
	else{
		if(!cnt%n) r=1;
		else r=n+1-(cnt%n);
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
}
