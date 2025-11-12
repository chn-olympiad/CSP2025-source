#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int score[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> score[i];
	}
	int xm_score = score[1];
	int xm_pm;
	sort(score+1,score+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		if (score[i]==xm_score){
			xm_pm=i;
		}
	}
	int x=1,y=1,direct=0;
	for (int i=2;i<=xm_pm;i++){
		if (direct==0){
			x++;
			if (x>n){
				x--;
				y++;
				direct=1;
			}
		}else{
			x--;
			if (x<1){
				x++;
				y++;
				direct=0;
			}
		}
	}
	cout << y << " " << x;
    return 0;
}
