#include<bits/stdc++.h>
#define int long long
const int Mn=998244353;
using namespace std;
int v[5055];
bool find(int s){
	for(auto p:v){
		if(p==s)return false;
	}
	return true;
}
int n,ans=0,o=0;
int a[5005];
vector<int> p;

void dod(int i,int sum,int ma,int num){//do or die
	if(i>n){
		if(sum>ma*2&&num>=3){
			int s=0;
			for(int v1:p){
				s=s*10+v1;
			}
			if(find(s)){
				v[o++]=s;
				ans++;
			}
		}
		return;
	}
	dod(i+1,sum,ma,num);
	
	sum+=a[i];
	p.push_back(i);
	ma=max(ma,a[i]);
	dod(i+1,sum,ma,num+1);
	p.pop_back();
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<2){
		cout<<0;
		return 0;
	}
	if(n==3){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dod(i,0,0,0);
		p.clear();
	}
	cout<<ans%Mn;
	return 0;
}

/*这题我大概能拿到40左右的部分分，这会总分就到了240,第三题一点都不想做 
时间不到10点，充足的很 
这题我有另一个疯狂的想法 
如果先全排列，然后去判断每一种排列符不符合要求即可 
但我不会全排列的写法 
全排列大概是O(n^3)吧，也比我这个2^n好很多了（应该大概是n^3吧？） 
第一题更是sort一下就过了 
第二题打个简单模拟也能满，数据范围摆在那里了 
第三题不会 
话说这次考试竟然一道多测都没有
CCF换出题人了？
感觉今年的难度比去年低一些，或许240还不够2=
希望大家都考的比我好 
也希望能看到迷惑行为大赏里面有我 
不过我可能很少会上luogu了 
学c++大概5年了，考了大概3年还是4年，s组每年都靠运进去，但今年复习s组却差了2分晋级 
明年我就高中了，要开始复习whk了，希望今年不留什么遗憾吧 
by zh_iieee
还有fuck CCF 也不怕这个禁赛3年了 

10:30
做了一下第三题，不会 
说不定交上去能拿10分 
就这样吧，今年的csp就到这里吧，唯一能算的遗憾是忘记了全排列怎么写 
明年再见，如果我还考的话，我会在不会的题里面写while(1) 
祝各位来年好运 
*/ 
