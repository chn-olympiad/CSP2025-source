#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000005];
	int b = 0;
	cin>>s;
	for(int i = 1;i<=s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			b++;
			a[b] = s[i];	
		}
	}
	for(int i = 1;i<b;i++)
		for(int j = 1;j<=b-i;j++)
			if(a[j] < a[j+1])	swap(a[j],a[j+1]);
	for(int i = 1;i<=b;i++)
		cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}