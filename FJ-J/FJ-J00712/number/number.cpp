#include <bits/stdc++.h>
using namespace std;

string s;
int num[1000005], top;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9')
			num[++top] = s[i] - '0';
	}
	sort(num + 1, num + top + 1, cmp);
	for(int i = 1;i <= top;i++)printf("%d", num[i]);
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
