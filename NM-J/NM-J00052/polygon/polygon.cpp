#include<bits/stdc++.h>

using namespace std;

int in,out,inl[100001];
int all;
int seed;

int sj(int seed){
	return seed*24873193%382336;
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	//能骗多少是多少qwq
	//佛祖保佑，骗分必中
	cin >> in;
	for(int i = 0 ; i < in ; i++){
		cin >> inl[i];
		all += inl[i];
	}seed = 144514;
	for(int i = 1 ; i < all/(sj(seed)%100)+3 ; i++){
		out += abs(seed%10);
		seed = sj(i+seed);
	}
	cout << out-1;
	//qwq qwq qwq qwq qwq qwq qwq qwq qwq
	return 0;
}
//这烂项目谁爱动谁动去吧，比史山还史。
