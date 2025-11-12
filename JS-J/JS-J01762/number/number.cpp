#include<bits/stdc++.h>
using namespace std;
vector<int>num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch=0;
	while(ch!='\n'&&ch!=-1){
		scanf("%c",&ch);
		// printf("%c",ch);
		if(isdigit(ch)){
			num.push_back(ch-'0');
		}
	}
	sort(num.begin(),num.end(),greater<int>());
	for(auto i:num){
		printf("%d",i);
	}
	printf("\n");
	return 0;
}