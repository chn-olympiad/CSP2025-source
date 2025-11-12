#include<bits/stdc++.h>
using namespace std;
int a[1000001];
char s[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s + 1);
	int n = strlen(s + 1);
	int k = 1;
	for(int i = 1;i <= n;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[k] = s[i] - '0';
			k++;
		}
	}
	sort(a + 1,a + k + 1);
	for(int i = k;i > 1;i--)
		cout << a[i];
	return 0;
}
