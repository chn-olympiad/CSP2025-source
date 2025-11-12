#include<bits/stdc++.h>
#include<stack>
using namespace std;

const int maxn = 1e4+5;
const int maxnn = 1e6+5;
int n,m,k,sum;
int cicty[maxn];
stack<int>s;

struct node{
	int a,b,m;
}road[maxnn];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		cin >> road[i].a >> road[i].b >> road[i].m;
	}
	for (int i = 1;i <= k;i++){
		int mm=0,arr[maxn];
		cin >> mm;
		for (int j = 1;j <= maxn;j++){
			cin >> arr[j];
		}	
	}
	for (int i = 1;i <= m;i++){
		if (cicty[road[i].a] == 0){
			if (cicty[road[i].b] == 0){
				sum+=road[i].m;
				cicty[road[i].a] = road[i].a;
				cicty[road[i].b] = road[i].b;
			}
			else{
				sum+=road[i].m;
				cicty[road[i].a] = road[i].a;
			}
		}
		else{
			if (cicty[road[i].b] == 0){
				sum+=road[i].m;
				cicty[road[i].b] = road[i].b;
			}
		}
	}
	cout << sum;
	return 0;
}
