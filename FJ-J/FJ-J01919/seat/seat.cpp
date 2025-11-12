#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;

int n,m,a[15][15],score[125],pos,r;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>score[i];
	r = score[1];
	
	sort(score+1,score+n*m,[](int a,int b){return a>b;});
	
	for(int i=1;i<=n*m;i++)
		if(score[i] == r) {
			pos = i;
			break;
		}
		
	int col = pos%n == 0 ? pos/n : pos/n+1;
	int t = pos%n == 0 ? n:pos%n;
	int bg = col%2==0 ? n:1;
	int row = bg == n ? bg-t+1 : bg+t-1;
	
	cout<<col<<' '<<row;
	return 0;
}
