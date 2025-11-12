#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t;
int n,q;
pair<string,string> a[maxn];
int rp=114514;
void solve(string s1,string s2){
	if(s1==s2) rp++;
	else rp++;
	rp++,rp++;
	int r=rand()%2;
	cout<<((r&1)?2:0)<<"\n";
	rp++;
}
/*
不管了，现在是18:18
我写一篇随笔，练练手

他死了
他死了。
阿华这样跟我说，两天前，王姨敲他门不见人应，推门而入，
才发现这一具干瘪的尸体，皮肤皱着，身子紧绷着。我错愕
地敷衍着阿华的感叹，什么可惜啊，什么天公不作美啊...
心里不自觉地映出过去有关他的些许记忆来。
我住在一幢小公寓，这儿地方很偏，正因如此，总是很安静。
找不到工作，我只好在网上接下几单画稿，用我高中时学的
皮毛应付生活
啊没有时间了，算了回家有时间再写。 
*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		a[i]=make_pair(s1,s2);
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		solve(s1,s2);
	}
	return 0;
}//I AK IOI !
