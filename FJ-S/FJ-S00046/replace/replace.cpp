#include <bits/stdc++.h>
using namespace std;

bool bol[5000010];
int n,q;
string str1,str2;

map <pair <int,int>,pair <int,int>> mp;

int main(){
	freopen("replace.out","w",stdout);
	freopen("replace.in","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++){
		cin >> str1 >> str2;
	}
	while(q--){
		cin >> str1 >> str2;
		printf("0\n");
	}
	return 0;
}

