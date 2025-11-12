#include <iostream>
#include <algorithm>
using namespace std;
int r = 0;
int x[10008][3];
int t = 0;
int n = 0;
int ca=0,cb=0,cc=0;
int o[3]={0,0,0};
int zj[10005];
int pai(int a,int b,int c){
	
	if (o[0] == a) {
		ca++;
		return 1;
	}
	if (o[0]==b){
		cb++;
		return 2;
	}
	if(o[0] == c){
		cc++;			
		return 3;
	}
}
int sum(int n){
	int sm = 0;
	for(int i = 0; i < n; i++) {
			sm += x[i][zj[i]];
	}
	return sm;
}
//int pan(int a,int b){
//	if
//}
bool cmp(int a,int b){
	return a>b;
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int h = 0; h < t;h++) {
		n = 0;
		cin >> n;
		for(int i = 0; i < 10008; i++) {
			for(int j = 0; j < 3; j++) {
				x[i][j]= 0;
			}
		}
		for (int i = 0; i < n; i++){
			int a,b,c;
			int hang=0;

			cin >> a >>b >>c;
			x[i][0] = a;
			x[i][1]=b;
			x[i][2]= c;
			o[0]=a;
			o[1]=b;
			o[2]=c;
			sort(o+0,o+3,cmp);
/*			for(int j = 0; j < 3; j++) {
				o[j]=op[j];
			}*/
			zj[i]=pai(a,b,c);
			o[0]=0;
			o[1] = 0;
			o[2] = 0;
 			r = sum(n);
 			for(int j = 0; j< 10005;j++) {
 				zj[j] = 0;
			 }
		}
		cout << r << endl;
	}
	return 0;
}//gameover
