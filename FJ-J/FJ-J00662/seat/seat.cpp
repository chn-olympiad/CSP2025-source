#include<bits/stdc++.h>
using namespace std;
int g[105];
int mc[105];
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int n;//座位的行数 
	int m;//座位的列数 
	fin >> n >> m;
	int tot = n * m;
	for(int i = 0;i < tot;i++){
		fin >> g[i];
	}
	int r = g[0];
	sort(g,g + tot);
	int mi = 1;
	for(int i = 0;i < tot;i++){
		mc[tot - i - 1] = g[i];
		if(g[i] == r){
			mi = tot - i;
		}
	}
	
//	cout << mi << " ";
	fout << (mi - 1) / n + 1 << " ";
	
//	cout << mi % (2 * n);
	if(mi % (2 * n) > n){
		fout << 2 * n - mi % (2 * n) + 1;
	}else{
		fout << mi % (2 * n);
	}
	fin.close();
	fout.close();
	return 0;
}
/*
2 2
 99 100 97 98
 
2 2
98 99 100 97

3 3 
9 1 4 3 2 5 6 7 8 

3 3
 94 95 96 97 98 99 100 93 92

4 4
12 1 2 3 4 5 6 7 8 9 10 11 13 14 15 16  

10 10 
99 10 1 2 3 4 5 6 7 8 9  11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98  100
*/

