#include<bits/stdc++.h>
using namespace std;
struct node{
	string s[2];//设置"二元组"
	int cc;//会变换多少个字母，可以提前筛选掉不要的 
};
bool cmp(node x,node y){
	return x.cc<y.cc;
}
node e[10005];//输入的 
int a,b; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;//代表"二元组"的数量以及询问次数
	for(int i=0;i<a;i++){
		cin>>e[i].s[0]>>e[i].s[1];
		for(int j=0;j<e[i].s[0].size();j++){
			if(e[i].s[0][j]!=e[i].s[1][j])e[i].cc++;
		}
	} 
	sort(e,e+a,cmp);//排序 
	while(b--){
		string o,p;
		long long ans=0;//方案数 
		cin>>o>>p;
		if(o.size()!=p.size()){
			printf("%d\n",0);//特判 
			continue;
		} 
		int df=0;//different的简写，指的是有几位不同。可以省下不少时间复杂度 
		for(int i=0;i<o.size();i++)if(o[i]!=p[i])df++; 
		for(int i=0;i<a;i++){//二分不确定来不来得及，先把暴力查找写了先 
			if(e[i].cc>df)break;
			if(e[i].cc<df)continue;
			for(int j=0;j<=o.size()-e[i].s[0].size();j++){
				int cg=df;//更改的数目。当cg==0的时候说明更改完成，方案数+1 //这上面的都没问题
				if(o[j]==e[i].s[0][0]&&p[j]==e[i].s[1][0]){//对的上
					for(int k=0;k<e[i].s[0].size();k++){
						if(o[j+k]==e[i].s[0][k]&&p[j+k]==e[i].s[1][k]){
							if(o[j+k]!=p[j+k])cg--;
						}
						else break;//不匹配，没法继续查找 
					}
				}
				if(cg==0)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
