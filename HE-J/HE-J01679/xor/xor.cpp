#include <bits/stdc++.h>
using namespace std;
const int Max = 5e5+5;
int He = 0,number = 0,jieguo = 0;
long long n,k,a[Max];
int cao(int a,int b,int wei){
	if(a==0&&b==0) return jieguo;
	int aa = a%2;
	int bb = b%2;
	int xiaA = a>>1;
	int xiaB = b>>1;
	if(aa!=bb){
		jieguo += wei;
	}
		wei*=2;
	cao(xiaA,xiaB,wei);
}
int yihuohe(int Begin,int End){
	int He = 0;
	if(End<Begin){
		return 0;
	}
	if(End>n){
		return 0;
	}
	for(int i = Begin;i<=End;i++){
		He = cao(He,a[i],1);
	}
	if(He == k) {
		number++;
	}
	yihuohe(Begin+1,End);
	yihuohe(Begin,End-1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	yihuohe(0,n);
	cout << number;

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
