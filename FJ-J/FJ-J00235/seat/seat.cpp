#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a,b,c[120],d,cnt,x,y,sss;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b>>d;
	c[d] = 1;
	for(long long i = 0; i < a*b - 1;++i){
		cin>>cnt;
		c[cnt] = 1;
	}
	x = 1;
	y = 1;
	sss = 0;
	for(long long i = 100; i >= 0;--i){
		if(i == d){
			cout<<x<<' '<<y;
				fclose(stdin);
				fclose(stdout);
			return 0;
		}
		if(c[i] == 1 && !(y == a && sss == 0) && !(sss == 1 && y == 1)){
			if(sss == 0){
				y++;
			}
			else {
				y--;
			}
		}
		else if(y == a && sss == 0){
			x++;
			sss = 1;
		}
		else if(sss == 1 && y == 1){
			sss = 0;
			x++;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
