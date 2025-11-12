#include <bits/stdc++.h>
using namespace std;
string s1,tmp;
int a[1000100],k = 1;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin >> s1;
	int s1len = s1.size();
	for (int i = 0;i < s1len;i += 1){
		if (s1[i] >= '0' && s1[i] <= '9'){
			tmp = s1[i];
			a[k] = stoi(tmp);
			k += 1;
		}
	}
	sort(a+1,a+k,cmp);
	for (int i = 1;i < k;i += 1){
		cout << a[i];
	}
	return 0;
}

