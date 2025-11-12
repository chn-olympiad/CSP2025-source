#include<iostream>
#include<algorithm>
#define MAXN 510
#define IO(x) freopen(#x ".in","r",stdin); freopen(#x ".out","w",stdout);
using namespace std;
int n,m,G[MAXN],Pos,Sum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)cin >> G[i];
	Sum=G[1];
	sort(G+1,G+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(G[i]==Sum){
			Pos=i;
			break;
		}
	}
	int c=Pos/n,r=0;
	if(Pos%n!=0)c++;
	int Last=Pos-(c-1)*n;	
	if(Last==0)r=n;
	else{
		if(c%2==0)r=n-Last+1;
		else r=Last;
	}
	cout << c << " " << r << endl;
	return 0;
}