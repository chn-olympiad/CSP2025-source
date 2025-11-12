#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

struct id {
	int sduan, roi, idx;
};

bool comp(id x, id y) {
	return x.sduan< y.sduan;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin>> n>> q;
	vector<string> sc[2];
	id sroidx[n];
	for (int i=0; i<n; i++) {
		string x, y;
		cin>> x>> y;
		int r= 0;
		while (x[r]== y[r] && r< x.length()) r++;
		int u= x.length()- 1;
		while (x[u]== y[u]&& u>= 0) u--;
		int diff= u- r+ 1;
		id idt;
		idt.sduan= (diff>0? diff: 0);
		idt.roi= r;
		idt.idx= i;
		sroidx[i]=idt;
		sc[0].push_back(x);
		sc[1].push_back(y);
	}
	sort(sroidx, sroidx+n, comp);
	vector<string> s[2];
	for (int i=0; i<n; i++) {
		s[0].push_back(sc[0][sroidx[i].idx]);
		s[1].push_back(sc[1][sroidx[i].idx]);
	}
	for (int j=0; j<q; j++) {
		string t1, t2;
		cin>> t1 >> t2;
		if (t1.length()!= t2.length()) {
			cout<< 0<<endl;
			continue;
		}
		int r= 0;
		while (t1[r]== t2[r] && r< t1.length()) r++;
		int u= t1.length()- 1;
		while (t1[u]== t2[u] && u>= 0) u--;
		int diff=u- r+ 1;
		diff= (diff>0? diff: 0);
		int ans= 0;
		for (int i=0; i<n; i++) {
			if (diff!= sroidx[i].sduan) continue;
				bool ok=true;
			for (int x=0; x<s[0][i].length(); x++) {
				if (t2[r- sroidx[i].roi+x]!= s[1][i][x] || t1[r-sroidx[i].roi+x]!= s[0][i][x]) {
					ok=false;
					break;
				}
			}
			if (ok)
				ans++;
		}
		cout<< ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
