#include<bits/stdc++.h>
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::string s;
	std::cin>>s;
	std::vector<int> a;
	for(char c:s){
		if(isdigit(c))a.push_back((int)(c-'0'));
	}
	auto cmp=[](int x,int y){
		return x>y;
	};
	sort(a.begin(),a.end(),cmp);
	for(int x:a)std::cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
