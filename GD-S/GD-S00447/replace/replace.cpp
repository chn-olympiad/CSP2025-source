#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,Q;
string s1[N],s2[N];
/*
b属性很有意思
先看整题
替换只能发生一次
那么肯定是直接找不同然后左右无限扩展了
kmp啊
丸辣

毕竟不用取模很可能不会很大
那么就直接开始找不同 
左右两边各开一个指针
从两边一直推推推推推
推不动了中间夹着的就是不同
接下来我们直接一个一个上手看行不行
首先比夹着的长度短的不用想肯定不行 
一样的可以直接比较 
比夹着的长度长的
到头来还是回到了kmp啊，补药啊 
*/

//何意味？ 
//int check(string x,string y){
//	for(int i = 0 ; i <= x.length()-y.length() ; ++i){
//		bool flag=1;
//		for(int j = 0 ; j < y.length() ; ++j){
//			if(x[i+j]!=y[j]){
//				flag=0;
//				break;
//			}
//		}
//		if(flag){
//			return i;
//		}
//	}
//	return -1;
//} 
int check(string x,string y){
	if(x.length()<y.length()) return -1; 
	for(int i = 0 ; i <= (int)x.length()-(int)y.length() ; ++i){
		if(x.substr(i,y.length())==y)
			return i;
	}
	return -1;
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i = 1 ; i <= n ; ++i){
		cin>>s1[i]>>s2[i];
	}
	string t1,t2,diff;
	while(Q--){
		int ans=0;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<"\n";
			continue; 
		}
		int l=0,r=t1.length()-1;
		while(t1[l]==t2[l])
			++l;
		while(t1[r]==t2[r])
			--r;
		diff=t1.substr(l,r-l+1);//diff标注在t1上 
		//
//		cout<<"// "<<l<<" "<<r<<" "<<diff<<"\n";
		// 
		/*
		好，接下来是困扰我四年的噩梦，kmp
		我们需要考虑的是，对于每一个s1,是否包含diff
		 
		*/
		for(int i = 1,tmp ; i <= n ; ++i){
			//
//			cout<<"/-/ "<<i<<" "<<check(s1[i],diff)<<"\n";
			//
			tmp=check(s1[i],diff);//返回diff开始处在s1中的下标 
			if(tmp>=0){
				/*拆成三段
				三段：
				第一段，s2[i]以左的部分
				t1.substr(0,l-tmp)
				第二段，s2[i] 
				第三段，s2右侧的部分
				第三段靠左的位置是
				l-tmp+s1[i].length()
				长度是
				t1.length()-(l-tmp+s1[i].length()) 
				*/
				string tmps="";
				//
//				cout<<"/;/ "<<0<<" "<<l-tmp<<"   ";
//				cout<<l-tmp+(int)s1[i].length()<<" ";
//				cout<<(int)t1.length()-(l-tmp+(int)s1[i].length());
//				cout<<"\n";
				//
				if(l-tmp>0)
					tmps=t1.substr(0,l-tmp);
				tmps=tmps+s2[i];
				if((int)t1.length()-(l-tmp+(int)s1[i].length())>0)
					tmps=tmps+t1.substr(l-tmp+(int)s1[i].length(),(int)t1.length()-(l-tmp+(int)s1[i].length()));
				//
//				cout<<"/+/ "<<tmps<<"\n";
				//
				if(tmps==t2)
					++ans;
			}
		}
		cout<<ans<<"\n";
	} 
	cout<<flush;
	return 0;
}
