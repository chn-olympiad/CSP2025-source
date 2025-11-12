#include<bits/stdc++.h>
using namespace std;
//已经139pts了，拿不到1=，去年貌似打了140pts来着
//看到字符串不想打，字符串烦死了 
//算了还是把这道题打了吧，不会遗憾 
const int N=4e5+5,zero=2e5+2;
struct Replace{
	int pos1,pos2,len;
};
int n,q;
vector<Replace> t[N];
int main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		Replace r;
		string a,b;cin>>a>>b;
		r.len=a.size();
		for(int j=0;j<a.size();j++){
			if(a[j]=='b') r.pos1=j;
			if(b[j]=='b') r.pos2=j;
		}
		t[r.pos2-r.pos1+zero].push_back(r);
	}
	while(q--){
		Replace r;
		string a,b;cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<a.size();j++){
			if(a[j]=='b') r.pos1=j;
			if(b[j]=='b') r.pos2=j;
		}
		r.len=a.size();
		int ans=0;
		for(auto &i:t[r.pos2-r.pos1+zero])
			if(i.pos1<=r.pos1&&i.len+(r.pos1-i.pos1)<=r.len)
				ans++;
		printf("%d\n",ans);
	}
	//期望0pts，还没调出来
	//现在期望10-25pts，球球了，不要卡我代码。
	//反正怎么说也差不多期望150了，可以1=吗？
	//算了算了，反正不是0分就可以打NOIP。
	//但是S组都拿不到1=，打NOIP有什么意义呢
	//然后被动：晚自习随机减少1-3节 还要持续将近1个月
	//我觉得会炸，不要那么贪心，90分已经很满足了。 
	//感觉就要结束了，还有10min，想上厕所…… 
	//然后打一句去年也打过的注释：
	//I hate Physic！！！！！ 
	//因为去年S组T2炸了 
	//累了，跟你聊聊天吧
	//听过未闻花名吗 
	return 0;
}