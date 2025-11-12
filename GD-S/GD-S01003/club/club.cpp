#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int wao( int a, int b, int c) {
	if (c== 0)return (a<b?a :b);
	if (a==0) return (b<c? b: c);
	if (b==0) return (a<c? a: c);
	return 0;
}

struct value {
	int x[3];
	int g;
	int diff;
};

bool comp0(value x, value y) {
	if (x.g== 0) {
		if (y.g!=0) return true;
		return x.diff< y.diff;
	}
	return false;
}

bool comp1(value x, value y) {
	if (x.g== 1) {
		if (y.g!=1) return true;
		return x.diff< y.diff;
	}
	return false;
}
bool comp2(value x, value y) {
	if (x.g== 2) {
		if (y.g!=2) return true;
		return x.diff< y.diff;
	}
	return false;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>> t;
	for (int q= 0; q< t; q++) {
		int n;
		cin>> n;
		int max= n/2;
		int t[] ={0, 0, 0 };
		value a[100007];
		for (int i=0; i<n; i++) {
			value v;
			cin>> v.x[0] >> v.x[1]>> v.x[2];
			v.g= (v.x[0]>v.x[1]? 0: 1);
			v.g= (v.x[v.g]>v.x[2]? v.g: 2);
			v.diff= wao(v.x[v.g]- v.x[0], v.x[v.g]- v.x[1], v.x[v.g]- v.x[2]);
			a[i]= v;
		}
		int ans= 0;
		for (int i=0; i<n; i++) {
			ans+= a[i].x[a[i].g];
			t[a[i].g]++;
		}
		if (t[0]> max) {
			sort(a, a+n, comp0);
			for (int u=0; u<t[0]- max; u++) {
				ans-= a[u].diff;
			}
		}
		if (t[1]> max) {
			sort(a, a+n, comp1);
			for (int u=0; u<t[1]- max; u++) {
				ans-= a[u].diff;
			}
		}
		if (t[2]> max) {
			sort(a, a+n, comp2);
			for (int u=0; u<t[2]- max; u++) {
				ans-= a[u].diff;
			}
		}
		 cout<< ans<< endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
