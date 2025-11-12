#include<bits/stdc++.h>
using namespace std;
string s;
int k=0,a[10000005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[k] = (s[i] - '0');
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++)
		cout << a[i];
	return 0;
}
