#include<bits/stdc++.h>
using namespace std;

int a[1000000];
char s[1000000];
bool cmp(int a,int b){
	return a > b;
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin >> s;
	int maxn = 0;
	int u = 0;
	int g = s[u];
	while(g != '\0'){
		g = s[u++];
		if(g >= '0' && g <= '9'){
			a[maxn++] = g-'0';
		}
	}
	sort(a,a+maxn-1,cmp); 
	for(int i = 0; i < maxn; i++){
		cout << a[i];
	}
	return 0;
}
