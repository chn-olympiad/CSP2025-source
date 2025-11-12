#include<bits/stdc++.h>
using namespace std;
const int Maxn = 105;
int lis[Maxn], n, m, a1, maxs, tmp, w, an, am;
int main()
{
	//freopen("C:/Users/lenovo/Desktop/aaa/seat/seat.in", "r", stdin);
	//freopen("C:/Users/lenovo/Desktop/aa.txt", "w", stdout);
	cin>>n>>m>>a1;
	lis[a1] = 1;
	maxs = a1;
	for(int i = 1;i<n*m;i++){
		cin>>tmp;
		lis[tmp] = 1;
		maxs = max(tmp, maxs);
	}
	while(maxs!=a1){
		w+=lis[maxs];
		maxs--;
		
	}
	an = w/(n)+1;
	am = (an&1)?(w%(n)+1):(n-(w%(n)));
	cout<<an<<" "<<am;
	return 0;	
} 
