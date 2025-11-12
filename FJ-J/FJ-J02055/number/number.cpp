#include<bits/stdc++.h>
#define int long long//不开见祖宗 
using namespace std;
/*
1.首先从字符串里提取所有数字 （O n） 
2.接着排序（O nlogn） 
3.输出 
4.AC 



*/
string s;
//int a[1000010]; //由于普通的sort被破坏，用vector 
vector<int> v;
int n;//数字的个数；
bool cmp(int a,int b){
	if(a>b) return true;
	else return false;
}
signed main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	//1.input the string
	 cin>>s;
	 //2.get the numbers
	 //最多有1e6个数字
	for(int i=0;i<=(int)(s.size()-1);i++){
		if(s[i]>='0'&&s[i]<='9'){
			
			n++;//数字的个数； 
			//a[i]=s[i]-'0';//转格式  
			int x=s[i]-'0';
			v.push_back(x);
			
			
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}//debug
	//3.排序
	sort(v.begin(),v.end(),greater<int>());
	 for(int i=0;i<n;i++){
		cout<<v[i];
	}
	return 0;
}

