#include<bits/stdc++.h>
using namespace std;
long long t,c[3][1000000],x_1,x_2,x_3,b[1][1000000],a[1000000][3],n; 
bool cmp(int x,int y){
	return x > y;
}
void p(int j){
	if(a[j][0] >= a[j][1]){
		if(a[j][0] >= a[j][2]){
			b[0][j] = 1;
			if(a[j][1] > a[j][2]) b[1][j] = 2;
			else b[1][j] = 3;
		}
		else{
			b[0][j] = 3;
			b[1][j] = 1;
		}
	}
	else{
		if(a[j][1] >= a[j][2]){
			b[0][j] = 2;
			if(a[j][0] > a[j][2]) b[1][j] = 1;
			else b[1][j] = 3;
		}
		else{
			b[0][j] = 3;
			b[1][j] = 2;
		}
	}
}
int g(int k,int n){
	int y_1 = 0,y_2 = 0,y_3 = 0,j_ie = 0;
	for(int i = 0;i < n;i++){
		if(a[i][k] < c[k][n/2 - 1] && b[0][i] == k){
			if(b[1][i] == 1) y_1 += 1;
			else if(b[1][i] == 2) y_2 += 1;
			else y_3 += 1;
		} 
	}
	if(k == 0){
		for(int i = x_2;i < (x_2 + y_2);i++) j_ie += c[1][i];
		for(int i = x_3;i < (x_3 + y_3);i++) j_ie += c[2][i];
	}
	else if(k == 1){
		for(int i = x_1;i < (x_1 + y_1);i++) j_ie += c[0][i];
		for(int i = x_3;i < (x_3 + y_3);i++) j_ie += c[2][i];
	}
	else{
		for(int i = x_1;i < (x_1 + y_1);i++) j_ie += c[0][i];
		for(int i = x_2;i < (x_2 + y_2);i++) j_ie += c[1][i];
	}
	return j_ie;
}
void f(int k,int n){
	int j_ie = 0;
	for(int i = 0;i < n/2;i++) j_ie += c[k][i];
	if(k = 0) {
		for(int i = 0;i < x_2;i++) j_ie += c[1][i];
		for(int i = 0;i < x_3;i++) j_ie += c[2][i];
	}
	else if(k = 1) {
		for(int i = 0;i < x_1;i++) j_ie += c[0][i];
		for(int i = 0;i < x_3;i++) j_ie += c[2][i];
	}
	else{
		for(int i = 0;i < x_1;i++) j_ie += c[0][i];
		for(int i = 0;i < x_2;i++) j_ie += c[1][i];
	}
	cout << (j_ie + g(k,n)) <<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0;i < t;i++){
		n = 0;
		for(int j = 0;j < 1000000;j++){
			for(int z = 0;z < 3;z++){
				c[z][j] = 0;
				a[j][z] = 0;
			}
			for(int z = 0;z < 2;z++) b[z][j] = 0;
		}
		cin >> n;
		for(int j = 0;j < n;j++){
			cin >> a[j][0];
			cin >> a[j][1];
			cin >> a[j][2];
			p(j);
			}
		x_1 = 0;
		x_2 = 0;
		x_3 = 0;
		for(int j = 0;j < n;j++){
			if(b[0][j] == 1) x_1 +=1;
			else if(b[0][j] == 2) x_2 += 1;
			else x_3 += 1;
		}
		for(int j = 0;j < n;j++) for(int z = 0;z < 3;z++) c[z][j] = a[j][z]; 
		for(int j = 0;j < n;j++) sort(c[j],c[j]+n,cmp);
		
		if(x_1 > n/2) f(0,n);
		else if(x_2 > n/2) f(1,n);
		else if(x_3 > n/2) f(2,n);
		else{
			int j_ie=0;
			for(int j=0;j < x_1;j++) j_ie += c[0][j];
			for(int j=0;j < x_2;j++) j_ie += c[1][j];
			for(int j=0;j < x_3;j++) j_ie += c[2][j];
			cout << j_ie <<endl;
		}
		}
	return 0;
}
