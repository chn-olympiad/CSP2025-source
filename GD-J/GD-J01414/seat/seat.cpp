#include<bits/stdc++.h>
#define debug 0
//debug 1 -> start debug
using namespace std;
int n,m,a[200],tag; 
bool cmp(int x,int y){return x >= y;}
void the_true_main(){
	cin >> n >> m;
	for(int i = 1;i<= n * m;i++){
		cin >> a[i];
		if(i == 1)tag = a[i];
	}
	sort(a + 1,a + n * m + 1,cmp);
	int where = 1;
	for(;where<= n * m && a[where] != tag;where++) ;
	int x,y;
	if(where % n == 0){
		x = where / n;
		y = n;
	}
	else{
		x = where / n + 1;
		y = where % n;
	}
	if(x % 2 == 0)y = n - y + 1;
	cout << x << " " << y;
	
}
int main(){
	#if debug == 1
	cout << "start debug\n";
	#else
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	#endif
	the_true_main();
	#if debug == 0
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
} 
