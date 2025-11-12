#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k=0,l=0,num=0,c[10000];
	bool t=false;
	string s;
	cin >>n>>m;
	cin >>s;
	for(int i=0;i < n;i++){
		cin >>c[i];
	}
	for(int j=0;j < n-1;j++){
		l=0;
		k=0;
		for(int i=0;i < n;i++){
			if(s[i] == 0 || k >= c[i]){
				k++;
				if(n-k < m){
					break;
				}
				continue;
			}
			else{
				l++;
			}
			if(l == m){
				num++;
				t = true;
				break;
			}
		}
		if(c[j] == c[j+1]){
			j++;
			if(t){
				num++;
			}
			t = false;
		}
		l = c[j];
		c[j] = c[j+1];
		c[j+1] = l;
	}
	cout <<num;
	return 0;
}
