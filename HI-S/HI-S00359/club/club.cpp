#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[3],b[3],c[3],d[3],sum=0,ma=-1;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n==2){
			cin>>a[0]>>a[1]>>a[2];
			cin>>b[0]>>b[1]>>b[2];
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(j!=k){
						ma=max(ma,a[j]+b[k]);
					}
				}
			}
			cout<<ma<<endl;
		}
		if(n==4){
			cin>>a[0]>>a[1]>>a[2];
			cin>>b[0]>>b[1]>>b[2];
			cin>>c[0]>>c[1]>>c[2];
			cin>>d[0]>>d[1]>>d[2];
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					for(int o=0;o<3;o++){
						for(int p=0;p<3;p++){
							if(j==k==o or j==k==p or j==o==p or k==o==p){
								continue;
								
							}
							else{
								
								ma=max(ma,a[j]+b[k]+c[o]+d[p]);
							}
						}
					}
				}
			}
			cout<<ma<<endl;
		}
		ma=-1;
	}
	
	return 0;
	/*
	爸爸
	妈妈
	你们可曾原谅他
	原谅他总不爱多说话 也不说有什么想法
	爸爸
	妈妈
	你们可曾离开他
	哦乖
	听话乖 
	没有一个能感到温暖的家
	从来都是担心和从来都是害怕
	还要我去顺从你们还要乖乖听话
	都说这是儿女对父母的报答
	你们说不论出现什么情况
	都要学会接受不要说什么废话
	哦我无可奈何的爸爸
	哦我可爱可怜的妈妈
	被迫
	接受
	你的错
	我的梦
	好难过
	对自己说
	这一切无所谓
	哦乖你们应该知道
	这样下去对我们谁都不好
	忘记过去一切你跟我走吧
	我给你安慰
	
	嗯 啊
	是这样
	嗯 啊
	请原谅
	
	那是从前梦的一天
	我们彼此相遇相恋
	无法摆脱梦的诱惑
	可梦
	把我们欺骗
	
	嗯 啊
	是这样
	嗯 啊
	请原谅
	
	被迫
	接受
	就算难过无所谓 
	无所谓 
	被迫
	接受
	无所谓 
	无所谓 
	*/
}
