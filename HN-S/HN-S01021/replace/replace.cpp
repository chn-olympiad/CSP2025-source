#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+67;
int n,q;
string a,b;
ll ans;
string s1[maxn];
string s2[maxn];
map<string,int>mp1;
map<string,int>mp2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n; i++){
		cin>>a;
		cin>>b;
		s1[i] = a;
		s2[i] = b;
		mp1[a]++;
		mp2[b]++;
	}
	for(int i = 1;i <= q; i++){
		cin>>a;
		cin>>b;
		for(int j = 1;j <= n; j++){
			int lz = a.length();
			int l = 0,r = lz-1;
			string r1;
			for(int k = 0;k < lz; k++){
				char s123 = a[k+1];
				r1.insert(k,&s123);
			} 
			bool flag = 0;
			while(l <= r && l < lz){
				r1.erase(0,1);
				r1.insert(lz-1,&a[r]);
				if(a == r1){
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				//有戏
				++ans;
				//真没招了 
			} 
		}
		printf("%lld",ans);
	}
	
	/*
	反正这里完全不会了
	那就随便骗骗分
	写点东西了
	
	T1的注释里全是英文
	但都是思路
	当时居然不知道有中文输入法
	T1顶天有100pts
	感觉就T1可以，还花了2h 
	T2完全没思路，图论的知识忘得一干二净 0pts
	T4顶天10pts，n <= 10 骗的
	T3怎么说呢，看能不能拿一点吧
		子串匹配的函数我竟然忘了！！！
		那么这题也就over了
	S顶天120，看能不能混个提二
	提三也不是不行，但每什么用了，上午的普及应该有290
	感觉普一没什么问题
	提一估计要190+
	肯定拿不到
	拿到了我还搞什么文化
	提二就可以了
	现在也只能把希望放在T3
	只有这里了
	
	T3怎么爆了！！！ 
	
	不过现在看感觉最多90了 
	
	the end 
	*/
	return 0;
}
