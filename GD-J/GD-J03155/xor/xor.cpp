#include<bits/stdc++.h>
using namespace std;
long xr(long x,long y){
	long as=0;
	long jz=1;
	while(x||y){
		long c=x%2;long d=y%2;
		x=x>>1;y=y>>1;
		if(c!=d)as+=jz;
		jz=jz<<1;
	}
	return as;
}//打一个XOR函数 
long a,b,c,d,ans;
long csp[500005];//小彩蛋~ 
bool cs[500005];//choose的简写，表示前面预处理的时候有没有排除掉 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);//先保存，后面还有bfs的做法 
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>csp[i];
		if(csp[i]==b){
			ans++;
			cs[i]=true;//顺便减少一点时间复杂度 
		}
	}
	for(int i=0;i<a;i++){
		if(cs[i])continue;//直接跳过 
		long k=csp[i];
		for(int j=i+1;j<a;j++){
			if(cs[j])break;//下一个就是前面精挑细选过的，直接退出 
			k=xr(csp[j],k);//细节csp[j] 
			if(k==b){
//				cout<<csp[i]<<' '<<csp[j]<<" more"<<"\n";
				i=j;//直接跳过
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
