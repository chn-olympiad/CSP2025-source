#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+5;
int a[N];
void dfs(int i){
	a[i] = rand();
	dfs(i+1);
}
int main(){
	dfs(1);
}
