#include <iostream>
#include <algorithm>
using namespace std;
struct seat_n{
	int score;
	bool F;
};
bool cmp(seat_n &a,seat_n &b){
	return a.score > b.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R,x;
	cin >> n >> m;
	cin >> R;
	seat_n sn[n*m];
	sn[0].F=1;
	sn[0].score=R;
	for (int i=1;i<m*n;i++){
		cin >> x;
		sn[i].F=0;
		sn[i].score=x;
	}
	sort(sn,sn+m*n,cmp);
	int ms=1,ns=0;
	bool ff=1;//ff:1ÕýÐò ff£º0µ¹Ðò 
	for (int i=0;i<m*n;i++){
		if ((ff && ns!=n) || ((!ff) && ns!=1)){
			if (ff){
				ns++;
			} else{
				ns--;
			}
		}else{
			ms++;
			ff=!ff;
		}
		//test
		//cout << "\n#####\ni:" << i << "\nf " << sn[i].F << " ns " << ns << " ms " << ms << " score " << sn[i].score << "\n";
		if (sn[i].F){
			
			cout << ms << " " << ns;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
