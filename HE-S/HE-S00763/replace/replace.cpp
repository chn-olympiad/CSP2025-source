//求什么?
//给出多组问题,求每组问题能够用多少种不同的方式替换

//怎么求?
//给出n,q
//然后给出n行,每一行是一个二元组(两个字符串)
//然后给出q行,每一行是两个字符串(替换前与替换后)
//对于每一组问题,判断n次是否可按照当前二元组替换 
//即按位一个一个比较 

#include<bits/stdc++.h>
using namespace std;

int neuf3_(string s,string aim3_){
	if(s.find(aim3_)<s.length()){
		return s.find(aim3_);
	}
	return -1;
}
//查找 

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	string dict3_[n][2];
	for(int i=0;i<n;i++){
		cin>>dict3_[i][0]>>dict3_[i][1];
	}
	//输入(通过)
	
	for(;q>0;q--){
		string s[2];
		cin>>s[0]>>s[1];//表示转换前后的字符串 
		
		int flag3_=0;//表示变形方法数量 
		for(int i=0;i<n;i++){
			int ori3_=neuf3_(s[0],dict3_[i][0]);
			int aim3_=neuf3_(s[1],dict3_[i][1]);
			//分别表示在下标为几的地方发现二元组的
			 
			if(ori3_==-1||aim3_==-1){
				continue;
			}
			
			else if(ori3_==aim3_){
				if(ori3_==0&&dict3_[i][0].length()==s[0].length()){//两串长度相同,起始位置为开头 
					flag3_++;
					//整个字符串直接被替换走 
				}
				
				else{//只有一部分被替换了 
					bool alsame3_=true;//是否全部都是相同的 
					
					for(int la=0,lb=0;la<s[0].length();la++,lb++){//l开头的是下标 
						if(la==ori3_){
							la+=dict3_[i][0].length();
							lb+=dict3_[i][1].length();
							//被替换的段不用判断,略过 
						}
						if(s[0][la]!=s[1][lb]){
							alsame3_=false;
							break;
						}
					}
					
					if(alsame3_){
						flag3_++;
					}
				}
			}
			
			else{
				continue;
			}
			
		}
		cout<<flag3_<<endl;
	}
	 
	return 0;
	//解注释 
} 
