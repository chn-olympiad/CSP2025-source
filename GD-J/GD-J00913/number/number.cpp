#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N];
int maxi = 9,mini;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0; i < s.size(); i++)
		if(s[i] >= '0' && s[i] <= '9'){
			a[s[i] - '0']++;
			if(maxi < s[i] - '0')
				maxi = s[i] - '0';
			if(mini > s[i] - '0')
				mini = s[i] - '0';
		}
	for(int i = maxi; i >= mini; i--)
		while(a[i] > 0){
			printf("%d",i);
			a[i]--;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
