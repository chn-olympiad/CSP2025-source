#include<bits/stdc++.h>
using namespace std;
int m[1000010];
int main(){
	freopen ("number1.ans","r",stdin);
	freopen ("number1.in","w",stdout);
	string n;
	cin>>n;
	int x = 0;
	for(int i=0;i<n.size();i++){
		if (n[i]-'1' + 1<10) {
			m[x] = n[i]- '1' + 1;
			x++;
		}
	}
	sort(m,m+x);
	for(int i=x-1;i>=0;i--){
		cout<<m[i];
	}
	return 0;
} 
