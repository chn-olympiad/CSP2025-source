#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m;
//30pts
int dfs(int f,int i,int zt){
	if(i>n)  return 0;
	if(zt==1)//是否是新区间 
		if(f^f==m)  return  1+dfs(a[i+1],i+1,1);
	if(f==m){
		return 1+dfs(a[i+1],i+1,1);
	}return  dfs(f^a[i],i+1,0);
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	cout<<dfs(a[1],1,1);
	return 0;
}//原G+三重审判+三重谋杀+三重错误+三重精错+三重混沌+八重终结+最后的呼吸（da，qi，ceng）+最终错误+最后的色彩+究极传说+三重裁决+全然不信+nightmare+D-Dream+X.Gaster+双向传说+决心猹+决心福+六魂衫+(最终boss)疯莎草纸 
//对面：大家不要留手，骨炮，骨头，蓝线给我往死里放！堵桥！！！颗秒！！！
//玩家：我可活个什么劲？！ 
//请不要暴露我的准考证号
