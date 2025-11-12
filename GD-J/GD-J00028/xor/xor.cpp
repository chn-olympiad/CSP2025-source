#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
map<int,bool>mp;
int s[N],n,k,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		s[i]^=s[i-1];
	}
	mp[0]=true;
	for(int i=1;i<=n;++i){
		if(mp[k^s[i]]){
			++cnt;
			mp.clear();
		}
		mp[s[i]]=true;
	}
	cout<<cnt;
	return 0;
}
/*
//freopen("xor.in ","w",stdout);
//freopen(" xor.out",'r',stdin); 
如果你被钓鱼了，那么可以看看我的T4qwq__ 

先看T4呀！！!

叠甲：记不住词了，写错不要说我呀 

我有一个梦想，我要造一个很大的房子，让天底下的老百姓都住进来--瑶瑶

平平凡凡，难道你也        喜欢我--瑶瑶 

哎，现在学习重要，等过年我要给桌桌充电一口气看到爽

求求了，多更点甜番吧！！！！！！

没想到这就10:44了，这是好事啊

为什么我要报名j组啊，亥死我力

算了，坐牢3个小时，就当为s组攒rp了

我决定了，现在睡觉，待会去玩手机！！！！！！ 
*/
