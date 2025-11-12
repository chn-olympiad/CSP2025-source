#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin>>s;
	sort(s.begin(),s.end(),greater<char>());
	bool has_not_zero=false; // 是否有非0数字 
	for(auto& c : s){
		if(isdigit(c)){
			if(c!='0'){
				has_not_zero=true;
			}else{
				if(!has_not_zero){ // 只有0，只输出一个0 
					putchar('0');
					return 0;
				}
			}
			putchar(c);
		}
	}
	return 0;
}
// 总的来说T1T2橙题  T3T4绿题(猜的)  难度比较正常(至少没有蓝题) 
