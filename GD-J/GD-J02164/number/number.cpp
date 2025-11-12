#include<cstdio>
#include<algorithm>
#include<vector>
bool cmp(char a,char b){
	return (int)(a)>(int)(b)?true:false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::vector<char> text;
	char now;
	while(scanf("%c",&now)!=EOF){
		text.push_back(now);
	}
	std::sort(text.begin(),text.begin()+text.size(),cmp);
	for(unsigned int a(0);a<text.size();++a){
		if(text[a]>='0' && text[a]<='9') printf("%c",text[a]);
	}
	return 0;
}
