#include<iostream>
using namespace std;
int n,m,R,p=1,ansx,ansy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>R;
	for(int i=2,x;i<=n*m;i++){
		cin>>x;
		if(x>R) p++;
	}
	ansx=(p-1)%m+1;
	ansy=(p+m-1)/m;
	if(!(ansy&1)) ansx=m-ansx+1;
	cout<<ansy<<" "<<ansx;
	return 0;
}
/*
计算比小R分数高的有多少个
列数直接除m向上取整
行数对m取模，在偶数列的话翻转即可 
*/
